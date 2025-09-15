#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<vector<int>> a(n, vector<int>(m));
		for(int i=0; i < n; i++)
			for(int j=0; j < m; j++)
				cin >> a[i][j];
				
		if ((n+m) % 2 == 0) {
			cout << "NO" << endl;
			continue;
		}
				
		vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(m, {1e9, -1e9}));
		
		dp[0][0] = {a[0][0], a[0][0]};
		
		for(int i=1; i < n; i++)
			dp[i][0] = {
				min(dp[i][0].first, min(dp[i-1][0].first + a[i][0], dp[i-1][0].second + a[i][0])), 
				max(dp[i][0].second, max(dp[i-1][0].first + a[i][0], dp[i-1][0].second + a[i][0]))
			};
		
		for(int j=1; j < m; j++) 
			dp[0][j] = {
				min(dp[0][j].first, min(dp[0][j-1].first + a[0][j], dp[0][j-1].second + a[0][j])), 
				max(dp[0][j].second, max(dp[0][j-1].first + a[0][j], dp[0][j-1].second + a[0][j]))
			};
		
		for(int i=1; i < n; i++) {
			for(int j=1; j < m; j++) {
				int up_mn = min(dp[i][j].first, min(dp[i][j-1].first + a[i][j], dp[i][j-1].second + a[i][j]));
				int lf_mn = min(dp[i][j].first, min(dp[i-1][j].first + a[i][j], dp[i-1][j].second + a[i][j]));
				
				int up_mx = max(dp[i][j].second, max(dp[i][j-1].first + a[i][j], dp[i][j-1].second + a[i][j]));
				int lf_mx = max(dp[i][j].second, max(dp[i-1][j].first + a[i][j], dp[i-1][j].second + a[i][j]));				
				
				dp[i][j] = {
					 min(up_mn, lf_mn),
					 max(up_mx, lf_mx)
				};
			}
		}
		
		if (dp[n-1][m-1].first <= 0 && dp[n-1][m-1].second >= 0)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}