#include<bits/stdc++.h>
using namespace std;

constexpr long long MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n);
		
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		vector<vector<long long>> dp(2, vector<long long>(n));
		
		dp[0][0] = dp[1][0] = 1;
		
		for(int i=1; i < n; i++) {
			if (a[i] >= a[i-1] && b[i] >= b[i-1])
				dp[0][i] += dp[0][i-1], dp[1][i] += dp[1][i-1];
			
			if (a[i] >= b[i-1] && b[i] >= a[i-1])
				dp[1][i] += dp[0][i-1], dp[0][i] += dp[1][i-1];
				
				dp[0][i] %= MOD;
				dp[1][i] %= MOD;
		}
		
		cout << (dp[0][n-1] + dp[1][n-1]) % MOD << "\n";
	}
}