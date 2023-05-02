#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, q;
		cin >> n >> q;
	
		vector<int> a(n);
		vector<long long> p(n+1);
		for(auto &ai : a) cin >> ai;
		
		for(int i=0; i < n; i++) {
			p[i+1] = p[i] + a[i];
		}
		
		while(q--) {
			int l, r, k;
			cin >> l >> r >> k;
			
			if ((p[n] - (p[r] - p[l-1]) + 1LL*k*(r-l+1)) % 2)
				cout << "YES" << endl;
			else 
				cout << "NO" << endl;	
		}
 	}
}