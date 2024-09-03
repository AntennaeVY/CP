#include<bits/stdc++.h>
using namespace std;

constexpr long long INF = 1e18;
constexpr int MAXN = 500 + 5;

long long memo[MAXN][MAXN];

long long dp(int a, int b) {
	if (b < a)
		swap(a, b);
	
	if (a < 0 || b < 0)
		return INF;
	
	if (a == b)
		return 1;
		
	if (memo[a][b] != INF)
		return memo[a][b];
		
	for(int i=1; i < a; i++) {
		memo[a][b] = min(memo[a][b], dp(i, b) + dp(a-i, b));
	}
	
	for(int i=1; i < b; i++) {
		memo[a][b] = min(memo[a][b], dp(a, i) + dp(a, b-i));
	}

	return memo[a][b];
}

int main() {
	int a, b;
	cin >> a >> b;
	
	for(int i=0; i <= max(a,b); i++) {
		for(int j=0; j <= max(a,b); j++) {
			memo[i][j] = INF;
		}
	}
	
	if (b < a)
		swap(a, b);
	
	cout << dp(a, b) - 1 << endl;
}