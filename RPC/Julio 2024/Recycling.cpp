#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;

	vector<vector<int>> st(25, vector<int>(n));
	for(int i=0; i < n; i++) {
		st[0][i] = a[i];
	}
	
	for(int i=1; i < 25; i++) {
		for(int j=0; j + (1 << i) <= n; j++) {
			st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i - 1))]);
		}
	}
	
	int ans = 0, start = 0, end = n-1;
	
	for(int i=0; i < n; i++) {
		int l=i, r = n;
		while(l + 1 < r) {
			int m = l + (r-l)/2;
			
			int lg = __lg(m - i + 1);
			int x = min(st[lg][i], st[lg][m - (1 << lg) + 1]);
			
			if (x >= a[i])
				l = m;
			else
				r = m;
		}
		
		int R = l;
		
		l = -1, r = i;
		while(l + 1 < r) {
			int m = l + (r-l)/2;
			
			int lg = __lg(i - m + 1);
			int x = min(st[lg][m], st[lg][i - (1 << lg) + 1]);
			
			if (x >= a[i])
				r = m;
			else
				l = m;
		}
		
		int L = r;
	
		if (a[i] * (R - L + 1) > ans)
			ans = a[i] * (R - L + 1), start = L, end = R;
		else if (a[i] * (R - L + 1) == ans && L < start)
			start = L, end = R;
	}
	
	cout << start + 1 << " " << end + 1 << " " << ans << endl;
}