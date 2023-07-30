#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	map<int, vector<int>> adj;
	map<pair<int, int>, int> cost;
	map<int, bool> visited;
	
	for(int i=0; i < n-1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
		
		cost[{u, v}] = c;
		cost[{v, u}] = c;
	}
	
	function<int(int)> dfs;
	
	dfs = [&](int root) -> int {
		visited[root] = true;
		
		int ans = 0;
		
		for(auto child : adj[root]) {
			if (visited[child])
				continue;
				
			ans = max(ans, dfs(child) + cost[{root, child}]);
		}
		
		return ans;
	};
	
	cout << dfs(0) << endl;
}