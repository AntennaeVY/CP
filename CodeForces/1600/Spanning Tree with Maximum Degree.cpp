#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	map<int, vector<int>> graph;
	map<int, int> deg;
	
	for(int i=0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
		
		deg[u]++;
		deg[v]++;
	}
	
	int root = 0;
	
	for(int i=1; i <= n; i++) {
		if (deg[i] > deg[root])
			root = i;
	}
	
	map<int, bool> vis, seen;
	queue<int> bfs;
	bfs.push(root);
	
	while(!bfs.empty()) {
		int u = bfs.front();
		bfs.pop();
		
		vis[u] = true;

		for(int v : graph[u]) {
			if (vis[v])
				continue;
	
			cout << u << " " << v << endl;
			
			vis[v] = true;	
			bfs.push(v);
		}
	}
}