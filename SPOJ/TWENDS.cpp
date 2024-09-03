#include<bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e3 + 5;

int v[MAXN];
long long memo[MAXN][MAXN];

long long dp(int i, int j) {
	if (i > j)
		return 0LL;
		
	if (memo[i][j] != -1)
		return memo[i][j];
		
	if (j-i+1 == 2)
		return memo[i][j] = max(v[i], v[j]);
		
	long long x, y;
	
	if (v[i+1] >= v[j])
		x = v[i] + dp(i+2, j);
	else
		x = v[i] + dp(i+1, j-1);
		
	if(v[i] >= v[j-1])
		y = v[j] + dp(i+1, j-1);
	else
		y = v[j] + dp(i, j-2);
		
	return memo[i][j] = max(x, y);
}


int main() {
	int t = 0;
	
	while(++t) {
		int n;
		cin >> n;
		
		if (n == 0)
			break;
		
		for(int i=0; i < n; i++)
			cin >> v[i];
	
		for(int i=0; i < n; i++) {
			for(int j=0; j < n; j++) {
				memo[i][j] = -1;
			}
		}
		
		long long sum = accumulate(v, v + n, 0LL);
		long long best = dp(0, n-1);
		
		cout << "In game " << t << ", the greedy strategy might lose by as many as " << 2*best - sum << " points." << endl;
	}
}