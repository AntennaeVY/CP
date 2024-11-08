#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<vector<int>> g(n+1, vector<int>());
	vector<long long> val(n+1);
	
	for(int i=0; i < n; i++) {
		cin >> val[i];
	}
	
	for(int i=0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		
		u--, v--;
		
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	vector<int> parent(n+1), add(n+1);
	
	auto dfs = [&](auto &&self, int u, int p = -1) -> void {
		parent[u] = p;
		
		for(auto &v : g[u])
			if (v != p)
				self(self, v, u);
	};
	
	dfs(dfs, 0);
	
	int q;
	cin >> q;
	
	while(q--) {
		int t, u;
		cin >> t >> u;
		
		u--;
		
		if (t == 1) {
			int x; 
			cin >> x;
			
			if (parent[u] != -1)
				val[parent[u]] += x;
			
			add[u] += x;
		}
		
		if (t == 2) {
			int ans = val[u];
			
			if (parent[u] != -1)
				ans += add[parent[u]];
			
			cout << ans << endl;
		}
	}
}