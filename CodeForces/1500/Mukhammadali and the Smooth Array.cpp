#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<long long> a(n), c(n);
		for(auto &ai : a) cin >> ai;
		for(auto &ci : c) cin >> ci;
		
		long long total = accumulate(c.begin(), c.end(), 0LL);
		
		long long ans = 1e18;
		vector<long long> dp(n);
		
		for(int i=0; i < n; i++)
			dp[i] = c[i];
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < i; j++) {
				if (a[j] <= a[i])
					dp[i] = max(dp[i], dp[j] + c[i]);
			}
			
			ans = min(ans, total - dp[i]);
		}
		
		cout << ans << "\n";
	}
}