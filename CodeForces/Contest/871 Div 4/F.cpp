#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		map<int, vector<int>> graph;
		
		for(int i=0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
 			
 		map<int, int> cnt, root;
 		
 		for(auto &[u, um] : graph) {
 			cnt[um.size()]++;
 			root[um.size()] = u;
 		}
 		
 		int mx = 0, x = 0, y = 0;
 		
 		for(auto &[i, j]: cnt) {
 			if (j == 1) {
 				x = i;
 				continue;
 			}
 			
 			mx = max(mx, i);
 		}
 		
 		if (x == 0) {
 			cout << mx << " " << mx-1 << endl;
 			continue;
 		}
 		
 		y = graph[graph[root[x]][0]].size() - 1;
 		
 		cout << x << " " << y << endl;
	}
}