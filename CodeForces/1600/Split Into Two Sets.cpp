#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		 int n;
		 cin >> n;
		 
		 vector<bool> vis(n+1, false);
		 vector<vector<int>> graph(n+1, vector<int>());
		 
		 bool ok = true;
		 
		 for(int i=0; i < n; i++) {
		 	int a, b;
		 	cin >> a >> b;
		 	
		 	graph[a].push_back(b);
		 	graph[b].push_back(a);
		 	
		 	if (a == b || graph[a].size() > 2 || graph[b].size() > 2)
		 		ok = false;
		 }
		 
		 if (!ok) {
		 	cout << "NO" << endl;
		 	continue;
		 }
		 
		 function<int(int)> dfs;
		 dfs = [&](int u) {
		 	vis[u] = true;
		 	
		 	for(auto &v : graph[u]) {
		 		if (vis[v])
		 			continue;
		 			
		 		return dfs(v) + 1;
		 	}
		 	
		 	return 1;
		 };
		 
		 for(int i=1; i <= n; i++) {
		 	if (vis[i])
		 		continue;
		 		
		 	ok &= (dfs(i) % 2 == 0);
		 }
		 
		 cout << (ok ? "YES" : "NO") << endl;
	}
}