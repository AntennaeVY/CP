#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int m, x;
		cin >> m >> x;
		
		vector<int> c(m), h(m);
		for(int i=0; i < m; i++) {
			cin >> c[i] >> h[i];
		}
		
		int s = accumulate(h.begin(), h.end(), 0);
		
		vector<ll> dp(s+1, 1e10);
		
		dp[0] = 0;
		
		for(int i=0; i < m; i++) {
			for(int j=s; j >= h[i]; j--) {
				if (dp[j - h[i]] + c[i] <= 1LL * i * x)
					dp[j] = min(dp[j], dp[j - h[i]] + c[i]);
			}
		}
		
		for(int j=s; j >= 0; j--) {
			if (dp[j] != 1e10) {
				cout << j << endl;
				break;
			}
		}
	}
}