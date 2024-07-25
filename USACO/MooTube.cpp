#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
	
	int n, q;
	cin >> n >> q;
	
	vector<vector<pair<int,int>>> graph(n);
	for(int i=0; i < n-1; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		
		p--, q--;
		
		graph[p].push_back({q, r});
		graph[q].push_back({p, r});
	}
	
	while(q--) {
		int k, v;
		cin >> k >> v;
		
		v--;
		
		int ans = 0;
		
		auto dfs = [&](auto &&self, int x, int p = -1, int best = 1e9) -> void {
			if (p != -1)
				ans += best >= k;
			
			for(auto [y, c] : graph[x]) {
				if (y == p)
					continue;
					
				self(self, y, x, min(best, c));
			}
		};
		
		dfs(dfs, v);
		
		cout << ans << "\n";
	}
}