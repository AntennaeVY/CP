#include<bits/stdc++.h>
using namespace std;

int main() {
	int ans = 0, sum = 1;
	
	for(int i=0; i < 2; i++) {
		int n;
		cin >> n;
		
		vector<vector<int>> g(n);
		
		for(int j=0; j < n-1; j++) {
			int u, v;
			cin >> u >> v;
			
			u--, v--;
			
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		vector<int> dist(n);
		
		auto dfs = [&](auto &&self, int u, int p = -1) -> void {
			if (p != -1)
				dist[u] = dist[p] + 1;
			
			for(auto &v : g[u])
				if (v != p)
					self(self, v, u);
		};
		
		dfs(dfs, 0);
		
		int a = 0;
		
		for(int j=1; j < n; j++) {
			if (dist[j] > dist[a])
				a = j;
		}
		
		fill(dist.begin(), dist.end(), 0);
		dfs(dfs, a);
		
		int diam = *max_element(dist.begin(), dist.end());
		
		ans = max(ans, diam);
		sum += (diam + 1) / 2;
	}
	
	ans = max(ans, sum);
	cout << ans << endl;
}