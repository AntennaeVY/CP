#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<int> L(m), R(m);
		for(int i=0; i < m; i++) {
			cin >> L[i] >> R[i];
		}		
		
		int q;
		cin >> q;
		
		vector<int> c(q);
		for(auto &ci : c) cin >> ci;
		
		int l=0, r=q+1;
		while(l+1 < r) {
			int x = l + (r-l)/2;
			bool ok = false;
			
			vector<int> a(n, 0), p(n+1, 0);
			for(int i=0; i < x; i++) {
				a[c[i] - 1] = 1;
			}
			
			for(int i=0; i < n; i++) {
				p[i+1] = p[i] + a[i];
			}
			
			for(int i=0; i < m; i++) {
				if (p[R[i]] - p[L[i]-1] > (R[i] - L[i] + 1)/2)
					ok = true;
			} 
			
			if (ok)
				r = x;
			else
				l = x;
		}
		
		if (r == q+1)
			cout << -1 << endl;
		else
			cout << r << endl;
	}
}