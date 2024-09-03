#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int INV2 = 500000004;

constexpr int MAXN = 500+5;
constexpr int MAXS = 1e5;

long long memo[MAXN][MAXS];

long long dp(int i, int sum, int x) {
	if (i == 0 && 2*x != sum)
		return 0;
		
	if (2*x == sum)
		return 1;
		
	if (memo[i][x] != -1)
		return memo[i][x];
		
	return memo[i][x] = (dp(i-1, sum, x+i) + dp(i-1, sum, x)) % MOD;
}

int main() {
	int n;
	cin >> n;
	
	for(int i=0; i <= n; i++)
		for(int j=0; j < MAXS; j++)
			memo[i][j] = -1;
	
	cout << (dp(n, n*(n+1)/2, 0) * INV2) % MOD << endl;
}