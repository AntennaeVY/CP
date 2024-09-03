#include<bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e4 + 5;
constexpr int INF = 1e9 + 7;

int memo[MAXN][MAXN];
int p[MAXN], a[MAXN];

int dp(int i, int j) {
	if (i == 0)
		return (j > 1 ? INF : a[i]);
		
	if (memo[i][j] != INF)
		return memo[i][j];
		
	if (j == 0)
		memo[i][j] = p[i] + dp(i-1, j+1);
	else
		memo[i][j] = min(p[i] + dp(i-1, j+1), a[i] + dp(i-1, j-1));
		
	return memo[i][j];
}

int main() {
	int n;
	cin >> n;
	
	for(int i=0; i < n; i++) {
		cin >> p[i] >> a[i];
	}
	
	for(int i=0; i <= n; i++) {
		for(int j=0; j <= n; j++) {
			memo[i][j] = INF;
		}
	}
	
	cout << dp(n-1, 0) << endl;
}