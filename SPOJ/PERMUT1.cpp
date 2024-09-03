#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<vector<long long>> dp(n+1, vector<long long>(k+1, 0));
	
		for(int i=1; i <= n; i++)
			dp[i][0] = 1;
	
		for(int i=1; i <= n; i++) {
			for(int j=1; j <= k; j++) {
				for(int x=0; x <= i-1; x++) {
					if (j-x < 0)
						break;
				
					dp[i][j] += dp[i-1][j-x];
				}
			}
		}
		
		cout << dp[n][k] << endl;
	}
}