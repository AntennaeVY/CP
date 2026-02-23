#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<pair<int,int>> graph(n+1);
		vector<int> ans(n+1);
	
		graph[0] = {1, 0};
		
		for(int i=1; i <= n; i++) {
			int l, r;
			cin >> l >> r;
			
			graph[i] = {l, r};
		}
		
		vector<long long> dp(n+1, -1);
		
		auto dfs = [&](auto &&self, int u) -> long long {
			if (dp[u] != -1)
				return dp[u];
			
			if (graph[u].first != 0 && graph[u].second != 0)
				return dp[u] = (4 + self(self, graph[u].first) + self(self, graph[u].second)) % MOD;
			else if (graph[u].first)
				return dp[u] = (2 + self(self, graph[u].first)) % MOD;
			else if (graph[u].second)
				return dp[u] = (2 + self(self, graph[u].second)) % MOD;
			else
				return dp[u] = 0;
		};
		
		dfs(dfs, 0);
		
		auto dfs2 = [&](auto &&self, int u, int p) -> void{		
			if (p >= 0) {
				ans[u] += 1 + dp[u] + ans[p];
				
				ans[u] %= MOD;
			}
				
			if (graph[u].first)
				self(self, graph[u].first, u);
				
			if (graph[u].second)
				self(self, graph[u].second, u);
				
		};
		
		dfs2(dfs2, 0, -1);
		
		for(int i=1; i <= n; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}