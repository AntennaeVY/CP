#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> a(n);
	for(int i=0; i < n; i++) {
		cin >> a[i];
		
		a[i]--;
	}
	
	map<int, vector<int>> graph;
	for(int i=0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		
		u--, v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	int d = 0;
	vector<int> ans(k, 0);
	vector<bool> vis(n);
	queue<int> q;
	
	q.push(0);
	vis[0] = true;
		
	while(!q.empty()) {
		int x = q.size();
		
		while(x--) {
			int u = q.front();
			q.pop();
			
			ans[a[u]] = d;
		
			for(auto &v : graph[u]) {
				if (vis[v])
					continue;
					
				vis[v] = true;
				q.push(v);
			}
		}
		
		d++;
	}
	
	for(auto &ansi : ans)
		cout << ansi << " ";
	cout << "\n";
}