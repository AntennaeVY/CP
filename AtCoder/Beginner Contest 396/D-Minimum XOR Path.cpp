#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int,long long>>> graph(n);
	for(int i=0; i < m; i++) {
		int u, v;
		long long w;
		
		cin >> u >> v >> w;
		
		u--, v--;
		
		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}

	long long ans = (1LL << 62);
	vector<bool> vis(n);
	
	auto dfs = [&](auto &&self, int u, long long x) -> void {
		vis[u] = true;
		
		if (u == n-1)
			ans = min(ans, x);
		
		for(auto &[v, w] : graph[u]) {
			if (!vis[v]) {
				x ^= w;
				self(self, v, x);
				vis[v] = false;
				x ^= w;
			}
		}
	};
	
	dfs(dfs, 0, 0LL);
	
	cout << ans << endl;
}