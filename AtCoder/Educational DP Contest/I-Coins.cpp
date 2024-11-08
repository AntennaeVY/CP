#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<long double> p(n);
	for(auto &pi : p) cin >> pi;
	
	vector<vector<long double>> dp(n+1, vector<long double>(n+1, 0));
	dp[0][0] = 1;

	for(int x=0; x <= n; x++) {
		for (int i=1; i <= n; i++) {
			if (x != 0)
				dp[x][i] = dp[x-1][i-1] * (p[i-1]);
				
			dp[x][i] += dp[x][i-1] * (1 - p[i-1]);
			
		}
	}
	
	long double ans = 0;
	
	for(int x=(n+1)/2; x <= n; x++) {
		ans += dp[x][n];
	}
	
	cout << fixed << setprecision(10) << ans << endl;
}