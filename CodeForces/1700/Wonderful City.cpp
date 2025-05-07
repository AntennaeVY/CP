#include<bits/stdc++.h>
using namespace std;

constexpr long long INF = 1e18;

long long solve(vector<vector<int>> &h, vector<int> &a) {
	int n = h.size();
	
	vector<vector<long long>> dp(n, vector<long long>(2, INF));
	dp[0][0] = 0, dp[0][1] = a[0];
	
	for(int i=1; i < n; i++) {
		for(int x=0; x < 2; x++) {
			for(int y=0; y < 2; y++) {
				bool ok = true;
				
				for(int j=0; j < n; j++) {
					ok &= (h[i][j] + x != h[i-1][j] + y);
				}
				
				if (ok) {
					if (x == 1) {
						dp[i][x] = min(dp[i][x], dp[i-1][y] + a[i]);
					}
					
					if (x == 0) {
						dp[i][x] = min(dp[i][x], dp[i-1][y]);
					}
				}
			}
		}
	}
	
	return min(dp[n-1][0], dp[n-1][1]);
}

void transpose(vector<vector<int>> &h) {
	int n = h.size();
	
	for(int i=0; i < n; i++) {
		for(int j=i+1; j < n; j++) {
			swap(h[i][j], h[j][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<vector<int>> h(n, vector<int>(n));
		for(int i=0; i < n; i++) {
			for(int j=0; j < n; j++) {
				cin >> h[i][j];
			}
		}
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		long long ansh = solve(h, a);
		
		if (ansh == INF) {
			cout << -1 << endl;
			continue;
		} 
		
		transpose(h);
		
		long long ansv = solve(h, b);
		
		if (ansv == INF) {
			cout << -1 << endl;
			continue;
		}
		
		cout << ansh + ansv << endl;
	}
}