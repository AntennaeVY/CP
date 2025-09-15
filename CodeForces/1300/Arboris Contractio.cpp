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
		
		map<int, vector<int>> g;
		
		for(int i=0; i < n-1; i++) {
			int u, v;
			cin >> u >> v;
			
			u--, v--;
			
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		int leaves = 0;
		vector<int> deg(n);
		
		for(int i=0; i < n; i++) {
			deg[i] = g[i].size();
			leaves += deg[i] == 1;
		}
		
		int mn = 1e9;
		
		for(int i=0; i < n; i++) {
			int cnt = 0;
			
			if (deg[i] == 1)
				cnt++;
				
			for(auto j : g[i])
				cnt += deg[j] == 1;
				
			mn = min(mn, leaves - cnt);
		}
		
		cout << mn << "\n";
	}
}