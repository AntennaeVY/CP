#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<vector<int>> graph(n);
		vector<int> deg(n);
		
		for(int i=0; i < n-1; i++) {
			int u, v;
			cin >> u >> v;
			
			u--, v--;
			
			graph[u].push_back(v);
			graph[v].push_back(u);
			
			deg[u]++, deg[v]++;
		}
		
		multiset<int> d;
		for(int i=0; i < n; i++) {
			d.insert(deg[i]);
		}
		
		int ans = 0;
		
		for(int i=0; i < n; i++) {
			int cnt = deg[i];
			
			d.erase(d.find(deg[i]));
			d.insert(-1);
			
			for(auto &v : graph[i]){
				d.erase(d.find(deg[v]));
				d.insert(deg[v] - 1);
			}
			
			cnt += *prev(d.end()) - 1;
			ans = max(ans, cnt);
			
			d.erase(d.find(-1));
			d.insert(deg[i]);
			
			for(auto &v : graph[i]) {
				d.erase(d.find(deg[v] - 1));
				d.insert(deg[v]);
			}
		}
		
		cout << ans << endl;
	}
}