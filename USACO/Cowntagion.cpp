#include<bits/stdc++.h>
using namespace std;

int main() {
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
	
	graph[0].push_back(-1);
	
	long long ans = 0;
	
	auto dfs = [&](auto &&self, int x, int p = -1) -> void {
		int m = graph[x].size();
		
		ans += __lg(2*m - 1) + m - 1;
		
		for(auto y : graph[x])
			if (y != p)
				self(self, y, x);
	};
	
	dfs(dfs, 0);
	
	cout << ans << endl;
}