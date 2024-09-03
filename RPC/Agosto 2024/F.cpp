#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e6 + 5;

int fib[MAXN], dp[MAXN];


int main() {
	fib[0] = 0, fib[1] = 1;
	
	for(int i=2; i < MAXN; i++) {
		fib[i] = (fib[i-1] + fib[i-2]) % MOD;
	}
	
	dp[0] = dp[1] = 0, dp[2] = 1;
	
	for(int i=3; i < MAXN; i++) {
		dp[i] = (dp[i-1] + fib[i-1]) % MOD + (dp[i-2] + fib[i-2]) % MOD;
		dp[i] %= MOD;
	}
	
	int n, q;
	cin >> n >> q;
	
	while(q--) {
		int s, t;
		cin >> s >> t;
		
		cout << dp[t-s+1] << endl;
	}
	
}