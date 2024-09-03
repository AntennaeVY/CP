#include<bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int MAXN = 5e3 + 5;
constexpr ll INF = 1e18;

ll memo[MAXN][MAXN];
ll sum[MAXN];
int a[MAXN];

ll dp(int i, int j) {
	if (i == j)
		return a[i];
		
	if (memo[i][j] != -INF)
		return memo[i][j];
		
	memo[i][j] = sum[j+1] - sum[i] - min(dp(i+1, j), dp(i, j-1));
	
	return memo[i][j];
}


int main() {
	int n;
	cin >> n;
	
	for(int i=0; i < n; i++)
		cin >> a[i];
	
	for(int i=0; i < n; i++) {
		for(int j=0; j < n; j++) {
			memo[i][j] = -INF;
		}
	}
	
	for(int i=0; i < n; i++) {
		sum[i+1] = sum[i] + a[i];
	}
	
	cout << dp(0, n-1) << endl;
}