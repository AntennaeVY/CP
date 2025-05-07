#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr ll MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		map<int, vector<int>> graph;
		map<int, ll> cnt;
		vector<int> p(n+1, -1);
		
		cnt[1] = 1;
		
		for(int i=2; i <= n; i++) {
			cin >> p[i];
			
			graph[i].push_back(p[i]);
			graph[p[i]].push_back(i);
		}	
		
		ll prev_level = 0;
		queue<int> q;
		q.push(1);
		
		while(!q.empty()) {
			int size = q.size();
			ll level = 0;
			
			for(int i=0; i < size; i++) {
				int u = q.front();
				q.pop();
				
				cnt[u] = (cnt[u] % MOD + prev_level % MOD) % MOD;
				
				if (p[u] != 1)
					cnt[u] = (cnt[u] % MOD - cnt[p[u]] % MOD + MOD) % MOD;

				for(auto v : graph[u])
					if (v != p[u])
						q.push(v);
				
				level = (level % MOD + cnt[u] % MOD) % MOD;
			}
			
			prev_level = level;
		}
		
		ll ans = 0;
		
		for(int i=1; i <= n; i++) {
			ans = (ans % MOD + cnt[i] % MOD) % MOD;
		}
		
		cout << ans << endl;
	}
}