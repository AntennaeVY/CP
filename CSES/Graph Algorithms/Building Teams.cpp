#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	map<int, vector<int>> adj;
	
	for(int i=0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	
	vector<bool> vis(n+1, false);
	vector<int> col(n+1, -1);
	
	function<bool(int, int)> dfs;
	
	dfs = [&](int node, int parent_color){
		vis[node] = true;
		col[node] = 1 - parent_color;
		
		bool ok = true;
		
		for(auto child : adj[node]) {
			if (vis[child] && col[child] == col[node])
				ok = false;
			else if (!vis[child])
				ok &= dfs(child, col[node]);
		}
		
		return ok;
	};
	
	bool can = true;
	
	for(int i=1; i <= n; i++) {
		if (!vis[i])
			can &= dfs(i, 1);
	}
	
	if (!can) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		for(int i=1; i <= n; i++) {
			cout << col[i] + 1 << " ";
		}
	}
}