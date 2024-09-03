#include<bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;

int main() {
	int n, x;
	cin >> n >> x;
	
	vector<int> c(n);
	for(auto &ci : c) cin >> ci;
	
	vector<int> dp(x+1, INF);
	dp[0] = 0;
	
	for(int i=0; i <= x; i++) {
		for(auto j : c)
			if (i + j <= x)
				dp[i+j] = min(dp[i+j], dp[i] + 1);
	}
	
	cout << (dp[x] == INF ? -1 : dp[x]) << endl;
}