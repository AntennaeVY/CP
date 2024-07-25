#include<bits/stdc++.h>
using namespace std;

int32_t main() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<pair<int, int>>> G(n+1);

	for(int i=0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	
	vector<vector<pair<int, int>>> up(n+1, vector<pair<int,int>>(21, {-1, 1e9+1}));
	vector<int> tin(n+1), tout(n+1), depth(n+1);
	int t = 0;
	
	function<void(int, int, int, int)> dfs;
	dfs = [&](int u, int p, int w, int d){
		tin[u] = t++;
		depth[u] = d;
		
		up[u][0] = {p, w};
		
		for(int i=1; i < 20; i++) {
			if (up[u][i-1].first == -1)
				break;
			
			int x = up[ up[u][i-1].first ][i-1].first;
			int wp = up[ up[u][i-1].first ][i-1].second;
			
			up[u][i].first = x;
			up[u][i].second = min(wp, up[u][i-1].second);
		}
		
		for(auto &[v, wi] : G[u])
			if (v != p)
				dfs(v, u, wi, d+1);
				
		tout[u] = t;
	};
	
	function<bool(int, int)> is_ancestor;
	is_ancestor = [&](int u, int v) {
		return tin[u] <= tin[v] && tout[u] >= tout[v];
	};
	
	function<int(int, int)> LCA;
	LCA = [&](int u, int v){
		if (is_ancestor(u, v))
			return u;
			
		if (is_ancestor(v, u))
			return v;
		
		for(int i=20; i >= 0; i--) {
			if (up[u][i].first == -1)
				continue;
			
			if (!is_ancestor(up[u][i].first, v))
				u = up[u][i].first;
		}
		
		return up[u][0].first;
	};
	
	function<pair<int,int>(int, int)> kth_ancestor;
	kth_ancestor = [&](int u, int k){
		int w = 1e9 + 1;
		
		for(int i=0; i < 20; i++) {
			if (((k >> i) & 1) == 0)
				continue;
				
			w = min(w, up[u][i].second);
			u = up[u][i].first;
		}
		
		return make_pair(u, w);
	};
	
	dfs(1, -1, 1e9 + 1, 0);
	
	int q;
	cin >> q;
	
	while(q--) {
		int a, b;
		cin >> a >> b;
		
		int lca = LCA(a, b);
		
		if (lca == a) {
			int k = depth[b] - depth[a];
			
			cout << kth_ancestor(b, k).second << "\n";
		} else if (lca == b) {
			int k = depth[a] - depth[b];
			
			cout << kth_ancestor(a, k).second << "\n";
		} else {
			int ka = depth[a] - depth[lca];
			int kb = depth[b] - depth[lca];
			
			auto aa = kth_ancestor(a, ka);
			auto ab = kth_ancestor(b, kb);
			
			cout << min(aa.second, ab.second) << "\n";
		}
	}
}