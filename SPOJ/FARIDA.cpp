#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	for(int x=1; x <= t; x++) {
		int n;
		cin >> n;
		
		if (n == 0) {
			cout << "Case " << x << ": 0" << endl;
			continue;
		}
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<long long> dp(n+1);
		dp[1] = a[0];
		
		for(int i=2; i <= n; i++) {
			dp[i] = max(dp[i-1], a[i-1] + dp[i-2]);
		}
		
		cout << "Case " << x << ": " << dp[n] << endl;
	}
}