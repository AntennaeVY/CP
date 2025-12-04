#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {	
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		sort(a.begin(), a.end());
		
		long long l = 2*a[0] - 1, r = 2*a.back();
		while(l + 1 < r) {
			long long m = l + (r-l) / 2;
			
			long long c = 0;
			
			long long R=n-1;
			for(int L=0; L <= R; L++) {
				while(L <= R && a[L] + a[R] > m) {
					R--;
				}
				
				if (L <= R) {
					c += 2*(R-L+1) - 1;
				}
			}
	
			
			if (c >= k)
				r = m;
			else
				l = m;
		}
		
		cout << r << "\n";
	}
}