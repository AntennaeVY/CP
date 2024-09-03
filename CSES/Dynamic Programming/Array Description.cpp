#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int MAXN = 1e5 + 5;
constexpr int MAXM = 100 + 5;

int n, m;
int a[MAXN];
int memo[MAXN][MAXM];

int dp(int i, int x) {
	if (i < 0)
		return 1;
		
	if (a[i] != 0 && abs(a[i] - x) > 1)
		return 0;
	
	if (memo[i][x] != -1)
		return memo[i][x];
	
	if (a[i] != 0)
		return memo[i][x] = dp(i-1, a[i]);
		
	memo[i][x] = dp(i-1, x);
		
	if (x > 1)
		memo[i][x] += dp(i-1, x-1), memo[i][x] %= MOD;
		
	if (x < m)
		memo[i][x] += dp(i-1, x+1), memo[i][x] %= MOD;

	return memo[i][x];
}

int main() {
	cin >> n >> m;
	
	for(int i=0; i < n; i++) {
		cin >> a[i];
		
		for(int j=0; j <= m; j++) {
			memo[i][j] = -1;
		}
	}
	
	memo[n-1][0] = 0;
	
	if (a[n-1] == 0) {
		for(int x=1; x <= m; x++) {
			memo[n-1][0] += dp(n-2, x);
			memo[n-1][0] %= MOD;
		}
	} else {
		memo[n-1][0] = dp(n-2, a[n-1]);
	}
	
	cout << memo[n-1][0] << endl;
}