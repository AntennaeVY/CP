#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		map<int, vector<pair<int, int>>> graph;
		
		for(int i=0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			
			u--, v--;
			
			string c;
			cin >> c;
			
			graph[u].emplace_back(v, (c == "imposter"));
			graph[v].emplace_back(u, (c == "imposter"));
		}
		
		int ans = 0;
		bool b = true;
		vector<int> color(n, -1);
		queue<int> q;
		
		for(int i=0; i < n; i++) {
			if (color[i] != -1)
				continue;
				
			int cnt[2] = {1, 0};
				
			q.push(i);
			color[i] = 0;
			
			while(!q.empty()) {
				int u = q.front();
				q.pop();
				
				for(auto [v, c] : graph[u]) {
					if (color[v] == -1) {
						color[v] = (color[u] ^ c);
						cnt[color[v]]++;
						
						q.push(v);
					}
					
					b &= ((color[v] ^ color[u]) == c);
				}
			}
			
			ans += max(cnt[0], cnt[1]);
		}
		
		if (b)
			cout << ans << endl;
		else 
			cout << -1 << endl;
	}
}