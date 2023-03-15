#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, q;
		cin >> n >> q;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int l=-1, r=n-1;
		while(l + 1 < r) {
			int m = l + (r-l)/2;
			int cq = q;
			
			bool ok = true;
			for(int i=m; i < n; i++) {
				if (cq == 0) {
					ok = false;
					break;
				}
				
				if (cq < a[i])
					cq--;
			}
			
			if (ok) 
				r = m;
			else
				l = m;
		}
		
		string ans(n, '0');
		for(int i=0; i < n; i++) {
			if (a[i] > q && i < r)
				continue;
			
			if (a[i] > q) {
				q--;
			}
			
			ans[i] = '1';
		}
		
		cout << ans << endl;
	}
}