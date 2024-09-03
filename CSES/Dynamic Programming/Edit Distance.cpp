#include<bits/stdc++.h>
using namespace std;

constexpr int MAXN = 5005;

int memo[MAXN][MAXN];

int n, m;
string s1, s2;

int dp(int i, int j) {
	if (i == 0)
		return j;
	
	if (j == 0)
		return i;
		
	if (memo[i][j] != -1)
		return memo[i][j];
		
	return memo[i][j] = min({
		dp(i-1, j) + 1,
		dp(i, j-1) + 1,
		dp(i-1, j-1) + (s1[i-1] != s2[j-1])
	});
}

int iterdp() {
	for(int i=0; i <= n; i++) {
		memo[i][0] = i;
	}
	
	for(int j=0; j <= m; j++) {
		memo[0][j] = j;
	}
	
	for(int i=1; i <= n; i++) {
		for(int j=1; j <= m; j++) {
			memo[i][j] = min({
				memo[i-1][j] + 1,
				memo[i][j-1] + 1,
				memo[i-1][j-1] + (s1[i-1] != s2[j-1])
			});
		}
	}
	
	return memo[n][m];
}

int main() {
	cin >> s1 >> s2;
	
	n=s1.size(), m=s2.size();
	
	for(int i=0; i <= n; i++) {
		for(int j=0; j <= m; j++) {
			memo[i][j] = -1;
		}
	}
	
	cout << iterdp() << endl;
}