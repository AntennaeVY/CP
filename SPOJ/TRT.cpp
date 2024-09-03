#include<bits/stdc++.h>
using namespace std;

constexpr int MAXN = 2e3 + 5;

int v[MAXN];
long long memo[MAXN][MAXN];

long long dp(int i, int j, long long k) {
	if (i > j)
		return 0;
		
	if (memo[i][j] != -1)
		return memo[i][j];
		
	return memo[i][j] = max(v[i]*k + dp(i+1, j, k+1), v[j]*k + dp(i, j-1, k+1));
}

int main() {
	int n;
	cin >> n;
	
	for(int i=0; i < n; i++) {
		for(int j=0; j < n; j++) {
			memo[i][j] = -1;
		}
	}
	
	for(int i=0; i < n; i++) 
		cin >> v[i];
		
	cout << dp(0, n-1, 1LL) << endl;
}