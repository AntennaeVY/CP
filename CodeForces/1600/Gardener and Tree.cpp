#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		map<int, set<int>> graph;
		map<int, int> edges;
		
		for(int i=1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			
			graph[u].insert(v);
			graph[v].insert(u);
			
			edges[u]++, edges[v]++;
		}
		
		queue<int> window;
		for(auto x : edges) {
			if (x.second == 1)
				window.push(x.first);
		}
		
		for(int i=0; i < k; i++) {
			if (graph.empty())
				break;
			
			int sz = window.size();
			for(int j=0; j < sz; j++) {
				int u = window.front();
				window.pop();
				
				for(auto v : graph[u]) {
					graph[v].erase(u);
					edges[v]--;
					
					if (edges[v] == 1)
						window.push(v);
				}
				
				graph.erase(u);
			}
		}
		
		cout << graph.size() << endl;
	}
}