#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		map<int, vector<pair<int, int>>> graph;
		vector<tuple<int,int,int>> res;
		
		for(int i=0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			
			a--, b--;
			
			res.emplace_back(a, b, d);
			graph[a].emplace_back(b, d);
			graph[b].emplace_back(a, -d);
		}
		
		vector<bool> vis(n, false);
		map<int, long long> coord;
		
		function<void(int)> dfs;
		dfs = [&](int x){
			vis[x] = true;
			
			for(auto [y, d] : graph[x]) {
				coord[y] = coord[x] + d;
				
				if (!vis[y])
					dfs(y);
			}
		};
		
		for(int i=0; i < n; i++) {
			if (vis[i])
				continue;
				
			dfs(i);
		}
		
		bool ok = true;
		
		for(int i=0; i < m; i++) {
			int a = get<0>(res[i]);
			int b = get<1>(res[i]);
			int d = get<2>(res[i]);
			
			ok &= (coord[b] == coord[a] + d);
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}