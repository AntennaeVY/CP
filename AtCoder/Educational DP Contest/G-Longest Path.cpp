#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	map<int, vector<int>> g;
	
	for(int i=0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		
		g[x].push_back(y);
	}
	
	map<int, int> size;
	
	auto dfs = [&](auto &&self, int x) -> int {
		if (size.find(x) != size.end())
			return size[x];
				
		size[x] = 0;
		
		for(auto &y : g[x])
			size[x] = max(size[x], 1 + self(self, y));
			
		return size[x];
	};
	
	int ans = 0;
	
	for(int i=1; i <= n; i++) {
		ans = max(ans, dfs(dfs, i));
	}
	
	cout << ans << endl;
}