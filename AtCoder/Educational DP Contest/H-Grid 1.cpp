#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

int main() {
	int h, w;
	cin >> h >> w;
	
	vector<string> grid(h);
	for(auto &gi : grid)
		cin >> gi;
		
	vector<vector<long long>> dp(h, vector<long long>(w));
	
	dp[h-1][w-1] = 1;
	
	for(int i=h-1; i >= 0; i--) {
		for(int j=w-1; j >= 0; j--) {
			if (j+1 < w && grid[i][j+1] == '.')
				dp[i][j] += dp[i][j+1];
				
			if (i+1 < h && grid[i+1][j] == '.')
				dp[i][j] += dp[i+1][j];
				
			dp[i][j] %= MOD;
		}
	}
	
	cout << dp[0][0] << endl;
}