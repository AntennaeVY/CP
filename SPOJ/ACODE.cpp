#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	while(s != "0") {
		int n = s.size();
		
		vector<long long> dp(n+1);
		dp[0] = 1, dp[1] = 1;
		
		for(int i=2; i <= n; i++) {
			if (s[i-1] != '0')
				dp[i] = dp[i-1];
			
			if (s[i-2] == '1' || s[i-2] == '2')
				dp[i] += dp[i-2];
		}

		cout << dp[n] << endl;
		cin >> s;
	}
}