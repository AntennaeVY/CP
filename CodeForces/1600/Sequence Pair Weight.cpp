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
		
		long long ans = 0;
		vector<long long> dp(n, 0);
		map<long long, long long> ps;
		
		ps[a[0]] = 1;
		
		for(int i=1; i < n; i++) {
			dp[i] = dp[i-1] + ps[a[i]];
			
			ps[a[i]] += i+1;
			ans += dp[i];
		}
		
		cout << ans << endl;
	}
}