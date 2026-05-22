#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<vector<int>> graph(n);
	
	for(int i=0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		
		u--, v--;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	vector<int> ans(n, n);
	vector<int> m(n);
	
	auto dfs = [&](auto &&self, int u, int p=-1) -> int {
		if (u > 0 && graph[u].size() == 1) 
			return m[u] = u;
		
		int mn = n;
		for(auto v : graph[u]) {
			if (v == p)
				continue;
				
			mn = min(mn, self(self, v, u));
		} 
		
		ans[u] = mn;
		
		return m[u] = min(mn, u);
	};
	
	dfs(dfs, 0);
	
	int mn = n, smn = n;
	for(auto v : graph[0]) {
		if (m[v] < mn) {
			smn = mn;
			mn = m[v];
		} else  {
			smn = min(m[v], smn);
		}
	}
	
	ans[0] = smn;
	
	for(int i=0; i < n; i++)
		cout << ans[i] << " \n"[i==n-1];
}