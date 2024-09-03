#include<bits/stdc++.h>
using namespace std;

constexpr int MAXN = 100;

bool a[MAXN];
int memo[MAXN][MAXN];

int dp(int i, int j) {
	if (i == 1)
		return j == 1;
		
	if (memo[i][j] != -1)
		return memo[i][j];
	
	if (a[i]) {
		if (j == 0)
			memo[i][j] = 0;
		else
			memo[i][j] = dp(i-1, j-1);
	} else {
		memo[i][j] = dp(i-1, j+1);
		
		if (j > 0)
			memo[i][j] += dp(i-1, j-1);
	}
		
	return memo[i][j];
}


int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		for(int i=1; i <= 2*n; i++) {
			a[i] = false;
			
			for(int j=0; j <= n; j++) {
				memo[i][j] = -1;
			}
		}
		
		for(int i=0; i < k; i++) {
			int x;
			cin >> x;
			
			a[x] = true;
		}
		
		cout << dp(2*n, 0) << endl;
	}
}