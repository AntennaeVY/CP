#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	string s;
	cin >> s;
	
	vector<vector<int>> graph(n);
	for(int i=0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		
		u--, v--;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	vector<int> c(n, -1);
	
	auto dfs = [&](auto &&self, int x, int k, int p = -1) -> void { 
		c[x] = k;
	
		for(auto y : graph[x])
			if (y != p && s[y] == s[x])	
				self(self, y, k, x);
	};
	
	int cnt = 0;
	
	for(int i=0; i < n; i++) {
		if (c[i] != -1)
			continue;
			
		dfs(dfs, i, cnt++);
	}
	
	while(m--) {
		int a, b;
		cin >> a >> b;
		
		a--, b--;
		
		char t;
		cin >> t;
		
		if (c[a] != c[b])
			cout << 1;
		else
			cout << (t == s[a] ? 1 : 0);
	}
}