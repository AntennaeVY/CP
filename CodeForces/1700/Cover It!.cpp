#include<bits/stdc++.h>
using namespace std;

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
		
		int parity = 0;
		vector<int> odd, even;
		
		map<int, bool> vis;
		queue<int> q;
		
		q.push(1);
		vis[1] = true;
		
		while(!q.empty()) {
			int size = q.size();
			
			for(int i=0; i < size; i++) {		
				int x = q.front();
				q.pop();
				
				for(auto y : graph[x]) {
					if (vis[y])
						continue;
					
					vis[y] = true;
					q.push(y);
				}
				
				
				if (parity)
					odd.push_back(x);
				else 
					even.push_back(x);
			}
			
			parity = 1-parity;
		}
		
		cout << min(odd.size(), even.size()) << endl;
		
		if (odd.size() < even.size())
			for(auto x : odd) cout << x << " ";
		else
			for(auto x : even) cout << x << " ";
			
		cout << endl;
	}
}