#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n), c(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		for(auto &ci : c) cin >> ci;
		
		vector<int> za(n), zb(n), zc(n);
		iota(za.begin(), za.end(), 0);
		iota(zb.begin(), zb.end(), 0);
		iota(zc.begin(), zc.end(), 0);
		
		sort(za.begin(), za.end(), [&](auto i, auto j){
			return a[i] > a[j];
		});
		
		sort(zb.begin(), zb.end(), [&](auto i, auto j){
			return b[i] > b[j];
		});
		
		sort(zc.begin(), zc.end(), [&](auto i, auto j){
			return c[i] > c[j];
		});

		int ans = 0;
		
		for(int i=0; i < 3; i++) {
			for(int j=0; j < 3; j++) {
				for(int k=0; k < 3; k++) {
					if (za[i] != zb[j] && za[i] != zc[k] && zb[j] != zc[k])
						ans = max(ans, a[za[i]] + b[zb[j]] + c[zc[k]]);
				}
			}
		}
		
		cout << ans << endl;
	}
}