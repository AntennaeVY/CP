#include<bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

int main() {
	int n;
	cin >> n;
	
	vector<int> dp(n+1, INF);
	dp[0] = 0;
	
	for(int i=1; i <= n; i++) {
		vector<int> d;
		int x = i;
		
		while(x) {
			d.push_back(x % 10);
			x /= 10;
		}
		
		for(auto j : d)
			dp[i] = min(dp[i], dp[i - j] + 1); 
	}
	
	cout << dp[n] << endl;
}