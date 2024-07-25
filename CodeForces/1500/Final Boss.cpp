#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int h, n;
		cin >> h >> n;
		
		vector<int> a(n), c(n);
		for(auto &ai : a) cin >> ai;
		for(auto &ci : c) cin >> ci;
		
		long long l = -1, r = 5e10;
		while(l + 1 < r) {
			long long x = l + (r-l)/2;
			
			long long sum = 0;
			
			for(int i=0; i < n; i++) {
				if (sum >= h)
					break;
				
				sum += (x / c[i] + 1) * a[i];
			}
			
			if (sum >= h)
				r = x;
			else
				l = x;
		}
		
		cout << r + 1 << endl;
	}
}