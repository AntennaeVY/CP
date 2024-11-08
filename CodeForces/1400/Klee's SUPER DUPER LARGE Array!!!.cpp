#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n,k;
		cin >> n >> k;
		
		auto p = [&](int i) {
			return 1LL*i*(i-1)/2 + 1LL*k*i;
		};
		
		long long s = 1LL*n*(n-1)/2 + 1LL*k*n;
		
		int l=0, r=n-1;
		while(l+1 < r) {
			int m = l + (r-l)/2;
			
			if (2*p(m) >= s)
				r = m;
			else
				l = m;
		}
		
		cout << min(abs(2*p(r) - s), abs(2*p(r-1) - s)) << endl;
		
	}
}