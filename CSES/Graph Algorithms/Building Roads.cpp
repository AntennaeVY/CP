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
	
	function<void(int)> dfs;
	
	dfs = [&](int root){
		vis[root] = true;
		
		for(auto child : adj[root]) {
			if (!vis[child])
				dfs(child);
		}
	};
	
	vector<int> ans;
	
	for(int i=1; i <= n; i++) {
		if (vis[i])
			continue;
			
		ans.push_back(i);
		dfs(i);
	}
	
	cout << ans.size() - 1 << endl;
	
	for(int i=1; i < ans.size(); i++) {
		cout << ans[i] << " " << ans[i-1] << endl;
	}
}