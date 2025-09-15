#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<vector<pair<int,int>>> graph(n+1);
		map<int, int> colors;
		int x = n+1;
		
		for(int i=0; i < m; i++) {
			int u, v, c;
			cin >> u >> v >> c;
			
			if (!colors[c])
				colors[c] = x++;
			
			graph[u].push_back({v, colors[c]});
			graph[v].push_back({u, colors[c]});	
		}
		
		int b, e;
		cin >> b >> e;
		
		vector<set<int>> bp(n + colors.size() + 5);
		
		for(int u=1; u <= n; u++) {
			for(auto &[v, c] : graph[u]) {	
				bp[u].insert(c);
				bp[c].insert(u);
			}
		}
		
		vector<bool> vis(bp.size(), false);
		vector<int> dist(bp.size(), -1);
		vector<int> q = { b };
		
		dist[b] = 0;
		
		for(int i=0; i < q.size(); i++) {
			for(auto v : bp[q[i]]) {
				if (dist[v] == -1) {
					q.push_back(v);
					dist[v] = dist[q[i]] + 1;
				} 
			}
		}
	
		
		cout << dist[e]/2 << "\n";
	}
}