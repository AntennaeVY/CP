#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	
	vector<int> h(n), s(n);
	for(auto &hi : h) cin >> hi;
	for(auto &si : s) cin >> si;
	
	vector<vector<int>> dp(n+1, vector<int>(x+1));
	
	for(int i=1; i <= n; i++) {
		for(int j=1; j <= x; j++) {
			dp[i][j] = dp[i-1][j];
			
			if (j - h[i-1] >= 0)
				dp[i][j] = max(dp[i][j], dp[i-1][j - h[i-1]] + s[i-1]);
		}
	}
	
	cout << dp[n][x] << endl;
}