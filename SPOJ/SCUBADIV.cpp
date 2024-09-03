#include<bits/stdc++.h>
using namespace std;

constexpr int MAXN =  1e3 + 5;
constexpr int MAXX = 100;
constexpr int MAXY = 100;
constexpr int INF = 1e9;

int dp[MAXN][MAXX][MAXY];

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int x, y;
		cin >> x >> y;
		
		int n;
		cin >> n;
		
		vector<int> a(n), b(n), w(n);
		for(int i=0; i < n; i++)
			cin >> a[i] >> b[i] >> w[i];
			
	   for(int i=0; i <= n; i++)
		for(int j=0; j <= x; j++) {
			for(int k=0; k <= y; k++) {
				dp[i][j][k] = INF;
			}
		}
		
		for(int i=0; i <= n; i++)
			dp[i][0][0] = 0;

		for(int i=1; i <= n; i++) {
			for(int j=0; j <= x; j++) {
				for(int k=0; k <= y; k++) {
					
					int dj = max(0, j - a[i-1]);
					int dk = max(0, k - b[i-1]);
					
					dp[i][j][k] = min(dp[i-1][j][k], w[i-1] + dp[i-1][dj][dk]);
				}
			}
		}
		
		cout << dp[n][x][y] << endl;
	}
}