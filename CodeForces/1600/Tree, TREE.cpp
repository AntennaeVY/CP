#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
	
		map<int,vector<int>> g;
		
		for(int i=0; i < n-1; i++) {
			int u, v;
			cin >> u >> v;
			
			u--, v--;
			
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		vector<int> c(n), p(n, -1);
		
		auto dfs = [&](auto &&self, int u, int parent = -1) -> int {
			int cnt = 1;
			
			for(auto &v : g[u])
				if (v != parent)
					cnt += self(self, v, u);
			
			p[u] = parent;
			return c[u] = cnt;
		};
		
		dfs(dfs, 0);
		
		long long ans = n;
		
		for(int u=0; u < n; u++) {
			for(auto &v : g[u]) {
				if (p[u] == v) {
					int cnt = n - c[u];
					
					if (c[u] >= k)
						ans += cnt;
					
				} else {
					int cnt = c[v];
					
					if (n - c[v] >= k)
						ans += cnt;
				}
			}
		}
		
		cout << ans << "\n";
	}
}