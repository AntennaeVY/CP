#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<vector<int>> g(n);
	
	for(int i=0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		
		u--, v--;
		
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	vector<int> dist_a(n), dist_b(n);
	
	auto dfs = [&](auto &&self, vector<int> &dist, int u, int p = -1) -> void {
		if (p != -1)
			dist[u] = dist[p] + 1;
		
		for(auto &v : g[u])
			if (v != p)
				self(self, dist, v, u);
	};
	
	dfs(dfs, dist_a, 0);
	
	int a = 0;
	
	for(int i=1; i < n; i++) {
		if (dist_a[i] > dist_a[a])
			a = i;
	}
	
	fill(dist_a.begin(), dist_a.end(), 0);
	dfs(dfs, dist_a, a);
	
	int b = 0;
	
	for(int i=1; i < n; i++) {
		if (dist_a[i] > dist_a[b])
			b = i;
	}
	
	dfs(dfs, dist_b, b);
	
	for(int i=0; i < n; i++) {
		cout << max(dist_a[i], dist_b[i]) << " ";
	}
	
	cout << endl;
}