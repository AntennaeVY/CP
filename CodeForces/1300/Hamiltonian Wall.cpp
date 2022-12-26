#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int m;
		cin >> m;
		
		int b = 0;
		vector<string> grid(2, string(m, '0'));
		
		for(int i=0; i < 2; i++) {
			for(int j=0; j < m; j++) {
				cin >> grid[i][j];
				
				b += (grid[i][j] == 'B');
			}
		}
		
		map<pair<int,int>, vector<pair<int,int>>> graph;
		
		for(int i=0; i < 2; i++) {
			for(int j=0; j < m; j++) {
				if (i == 0 && grid[i+1][j] == 'B')
					graph[{i, j}].push_back({i+1, j});
					
				if (i == 1 && grid[i-1][j] == 'B')
					graph[{i, j}].push_back({i-1, j});
					
				if (j < m-1 && grid[i][j+1] == 'B')
					graph[{i, j}].push_back({i, j+1});					
			}
		}
		
		map<pair<int,int>, bool> visited;
		
		auto dfs = [&](pair<int,int> node, auto&& dfs) {
			if (visited[node] || grid[node.first][node.second] == 'W')
				return 0;
				
			visited[node] = true;
			
			int ans = 0;
			
			for (auto &adj : graph[node]) {
				if (visited[adj])
					continue;
					
				ans = max(ans, dfs(adj, dfs));
			}
			
			return 1 + ans;
		};
		
		int ans = 0;
		
		for(int j=0; j < m; j++) {
			ans = dfs({0, j}, dfs);
			
			visited.clear();
			
			ans = max(ans, dfs({1, j}, dfs));
			
			if (grid[0][j] == 'B' || grid[1][j] == 'B')
				break;
		}
		
		cout << (ans == b ? "YES" : "NO" ) << endl;
	}
}