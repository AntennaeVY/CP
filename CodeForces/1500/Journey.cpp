#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	map<int, vector<int>> graph;
	
	for(int i=0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	graph[1].push_back(-1);
	
	vector<long double> ans(n+1);
	
	auto dfs = [&](auto &&self, int x, int p = -1) -> void {
		for(auto y : graph[x]) {
			if (y == p)
				continue;
				
			self(self, y, x);
			
			ans[x] += (ans[y] + 1) / (graph[x].size() - 1);
		}
	
	};
	
	dfs(dfs, 1);
	
	cout << fixed << setprecision(15) << ans[1] << endl;
}