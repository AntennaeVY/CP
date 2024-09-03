#include<bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

int main() {
	int n, x;
	cin >> n >> x;
	
	vector<int> c(n);
	for(auto &ci : c) cin >> ci;
	
	vector<int> dp(x+1);
	dp[0] = 1;
	
	for(int i=1; i <= x; i++) {
		for(auto j : c)
			if (i - j >= 0)
				dp[i] += dp[i-j], dp[i] %= mod;
	}
	
	cout << dp[x] << endl;
}