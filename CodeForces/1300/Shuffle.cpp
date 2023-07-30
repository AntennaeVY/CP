#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n,x,m;
		cin >> n >> x >> m;
		
		int L = x, R = x;
		
		for(int i=0; i < m; i++) {
			int l, r;
			cin >> l >> r;
			
			if (max(l,L) <= min(r,R)) {
				L = min(l, L);
				R = max(r, R);
			}
		}
		
		cout << R-L+1 << endl;
	}
}