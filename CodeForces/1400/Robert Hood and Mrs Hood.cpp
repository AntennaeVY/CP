#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, d, k;
		cin >> n >> d >> k;
		
		vector<int> open(n+1), close(n+1);
	
		while(k--) {
			int l, r;
			cin >> l >> r;
			
			open[l-1]++, close[r]++;
		}
		
		for(int i=0; i < n; i++) 
			open[i+1] += open[i], close[i+1] += close[i];
		
		int mn = 1e9, mx = -1;
		int a = 1, b = 1;
		
		for(int i=0; i+d-1 < n; i++) {
			int cnt = open[i + d-1] - close[i];
			
			if (cnt > mx)
				mx = cnt, a = i+1;
			
			if (cnt < mn)
				mn = cnt, b = i+1;
		}
		
		assert(a >= 1 && a <= n && b >= 1 && b <= n);
		
		cout << a << " " << b << endl;
	}
}