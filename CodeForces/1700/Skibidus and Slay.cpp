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
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		map<int, vector<int>> g;
		for(int i=0; i < n-1; i++) {
			int u, v;
			cin >> u >> v;
			
			u--, v--;
			
			g[u].push_back(v);
			g[v].push_back(u);
		}
	
		string ans = string(n, '0');
		
		for(int i=0; i < n; i++) {
			map<int, int> m;
			m[a[i]]++;
			
			for(auto &v : g[i]) {
				m[a[v]]++;
			}
			
			for(auto &[x, y] : m) {
				if (y >= 2) 
					ans[x-1] = '1';
			}
		}
		
		cout << ans << '\n';
	}
}