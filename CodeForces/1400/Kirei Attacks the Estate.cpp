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
		
		vector<long long> a(n);
		for(auto &ai : a) cin >> ai;
		
		map<int, vector<int>> g;
		for(int i=0; i < n-1; i++) {
			int u, v;
			cin >> u >> v;
			
			u--, v--;
			
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		vector<long long> ans(n);
		ans[0] = a[0];
		
		function<void(int,int,int,long long,long long)> dfs;
		
		dfs = [&](
			int u, int p, int l, 
			long long s_odd, long long s_even
		) -> void {
			if (l % 2) {
				s_even -= a[u];
				
				if (s_odd + a[u] > a[u])
					s_odd += a[u];
				else
					s_odd = a[u];
					
				ans[u] = s_odd;
			} else {
				s_odd -= a[u];
				
				if (s_even + a[u] > a[u])
					s_even += a[u];
				else
					s_even = a[u];
					
				ans[u] = s_even;
			}
			
			for(auto v : g[u])
				if (v != p)
					dfs(v, u, l+1, s_odd, s_even);
		};
		
		dfs(0, -1, 1, 0, 0);
		
		for(int i=0; i < n; i++) {
			cout << ans[i] << " ";
		}
		
		cout << "\n";
	}
}