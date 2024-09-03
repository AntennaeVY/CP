#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;

ll dp2(int i, int j, vector<vector<ll>> &a, vector<vector<ll>> &memo2) {
	if (j >= m)
		return 0;
		
	if (memo2[i][j] != -1)
		return memo2[i][j];
		
	return memo2[i][j] = max(a[i][j] + dp2(i, j+2, a, memo2), dp2(i, j+1, a, memo2));
}

ll dp1(int i, vector<vector<ll>> &a, vector<ll> &memo1, vector<vector<ll>> &memo2) {
	if (i >= n)
		return 0;
		
	if (memo1[i] != -1)
		return memo1[i];
		
	return memo1[i] = max(
		dp2(i, 0, a, memo2) + dp1(i+2, a, memo1, memo2),
		dp1(i+1, a, memo1, memo2)
	);
	
}


int main() {
	while(true) {
		cin >> n >> m;
		
		if (n == 0 && m == 0)
			break;
		
		vector<vector<ll>> a(n, vector<ll>(m, -1));
		vector<vector<ll>> memo2(a);
		vector<ll> memo1(n, -1);
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		
		cout << dp1(0, a, memo1, memo2) << endl;
	}
}