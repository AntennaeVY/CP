#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		map<int, set<int>> graph;
		
		for(int i=0; i < n; i++) {
			graph[i+1].insert(a[i]);
			graph[a[i]].insert(i+1);
		}
		
		map<int, bool> visited;
		int mx = 0, mn = 0, non_cyclic = 0;
		
		function<int(int)> component_size;
		function<bool(int)> is_cyclic;
		
		component_size = [&](int v) {
			if (visited[v])
				return 0;
				
			visited[v] = true;
			int size = 1;
			
			for(auto u : graph[v]) {
				size += component_size(u);
			}
			
			return size;
		};
		
		is_cyclic = [&](int v) {
			map<int, bool> vis;
			queue<int> q;
			bool ok = true;
			
			q.push(v);
			
			while(!q.empty()) {
				int u = q.front();
				q.pop();
				
				vis[u] = true;
				ok &= (graph[u].size() == 2);
				
				for(auto x : graph[u]) {
					if (vis[x])
						continue;
						
					q.push(x);
				}
			}
			
			return ok;
		};
		
		for(int i=1; i <= n; i++) {
			if (visited[i])
				continue;
				
			int size = component_size(i);
			bool cyclic = is_cyclic(i);
			
			if (size > 2 && cyclic)
				mn++;
			else 
				non_cyclic++;
				
			mx++;
		}
		
		mn += (non_cyclic != 0);
		
		cout << mn << " " << mx << endl;
	}
}