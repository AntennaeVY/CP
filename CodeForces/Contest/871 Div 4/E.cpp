#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<vector<int>> grid(n, vector<int>(m));
		for(auto &r : grid) {
			for(auto &c : r) {
				cin >> c;
			}
		}
		
		map<pair<int, int>, bool> vis;
		
		function<int(int, int)> dfs;
		dfs = [&](int i, int j){
			if (grid[i][j] == 0 || vis[{i, j}])
				return 0;
				
			vis[{i, j}] = true;
				
			int cnt = grid[i][j];
			
			if (i > 0)
				cnt += dfs(i-1, j);
			
			if (i < n-1)
				cnt += dfs(i+1, j);
				
			if (j > 0)
				cnt += dfs(i, j-1);
				
			if (j < m-1)
				cnt += dfs(i, j+1);
				
			return cnt;
		};
		
		
		int mx = 0;
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				mx = max(mx, dfs(i, j));
			}
		}
		
		cout << mx << endl;
	}
}