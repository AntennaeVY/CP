#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<pair<int,int>>> graph(n);
	for(int i=0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		
		x--, y--;
		
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}
	
	vector<bool> vis(n);
	vector<long long> ans(n);
	
	for(int k=0; k < n; k++) {
		if (vis[k])
			continue;
			
		vector<long long> comp;
		queue<int> q;
		
		q.push(k);
		vis[k] = true;
		
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			
			
			comp.push_back(u);
			
			for(auto &[v, w] : graph[u])
				if (!vis[v]){
					ans[v] = (ans[u] ^ w);
					vis[v] = true;
					q.push(v);
				} else {
					if (ans[v] != (ans[u] ^ w)) {
						cout << -1 << "\n";
						return 0;
					}
				}
		}
		
		for(int i=0; i < 63; i++) {
			int size = comp.size();
			int cnt = 0;
			
			for(int j=0; j < size; j++) {
				cnt += ((ans[comp[j]] >> i) & 1LL);
			}
			
			
			if (cnt > size - cnt)
				for(int j=0; j < size; j++)
					ans[comp[j]] ^= (1LL << i);
		}
	}
	
	for(auto &ansi : ans)
		cout << ansi << " ";
	cout << "\n";
}