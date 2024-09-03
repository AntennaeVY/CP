#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e6 + 6;

long long dp[MAXN][2];

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		dp[1][0] = dp[1][1] = 1;
		
		for(int i=2; i <= n; i++) {
			dp[i][0] = dp[i-1][1] + 2*dp[i-1][0];	
			dp[i][0] %= MOD;
			
			dp[i][1] = 4*dp[i-1][1] + dp[i-1][0];
			dp[i][1] %= MOD;
		}
		
		cout << (dp[n][0] + dp[n][1]) % MOD << endl;
	}
}