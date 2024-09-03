#include<bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	
	vector<string> g(n);
	for(auto &gi : g) cin >> gi;
	
	vector<vector<int>> dp(n, vector<int>(n));

	dp[n-1][n-1] = (g[n-1][n-1] == '.');
	
	for(int i=n-1; i >= 0; i--) {
		for(int j=n-1; j >= 0; j--) {
			if (g[i][j] == '*')
				continue;
				
			if (i+1 < n)
				dp[i][j] += dp[i+1][j];
				
			if (j+1 < n)
				dp[i][j] += dp[i][j+1];
				
			dp[i][j] %= mod;
		}
	}
	
	cout << dp[0][0] << endl;
}