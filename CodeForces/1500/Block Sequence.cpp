#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<int> dp(n);
		
		dp[n-1] = 1;
		
		for(int i=n-2; i >= 0; i--) {
			int c = n+1;
			
			if (i + a[i] + 1 < n)
				c = dp[i + a[i] + 1];
			else if (i + a[i] + 1 == n)
				c = 0;
			
			dp[i] = min(dp[i+1] + 1, c);
		}
		
		cout << dp[0] << endl;
	}
}