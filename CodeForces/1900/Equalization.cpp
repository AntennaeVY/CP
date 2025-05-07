#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
		long long dp[63][63];
		memset(dp,0x3f,sizeof(dp));
		
		dp[0][0] = 0;
		
		for(int i=1; i < 63; i++) {
			for(int j=62; j >= 0; j--) {
				for(int k=62; k >= 0; k--) {
					if (i <= j) 
						dp[j][k] = min(dp[j][k], dp[j-i][k] + (1LL << i));
					if (i <= k) 
						dp[j][k] = min(dp[j][k], dp[j][k-i] + (1LL << i));
				}
			}
		}
		
	
	while(t--) {
		long long x, y;
		cin >> x >> y;

		long long ans = 1e18;
		
		for(int i=0; i < 63; i++) {
			for(int j=0; j < 63; j++) {
				if ((x >> i) == (y >> j))
					ans = min(ans, dp[i][j]);
			}
		}
		
		cout << ans << "\n";
	}
}