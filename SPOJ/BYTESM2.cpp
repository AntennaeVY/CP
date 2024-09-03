#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int h, w;
		cin >> h >> w;
		
		vector<vector<int>> g(h, vector<int>(w));
		for(auto &hi : g)
			for(auto &wi : hi)
				cin >> wi;
				
		vector<vector<int>> dp(h, vector<int>(w));
		copy(g[0].begin(), g[0].end(), dp[0].begin());
		
		for(int i=1; i < h; i++) {
			for(int j=0; j < w; j++) {
				dp[i][j] = dp[i-1][j];
				
				if (j-1 >= 0)
					dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
				
				if (j+1 < w)
					dp[i][j] = max(dp[i][j], dp[i-1][j+1]);
					
				dp[i][j] += g[i][j];
			}
		}
			
		cout << *max_element(dp.back().begin(), dp.back().end()) << endl;
	}
}