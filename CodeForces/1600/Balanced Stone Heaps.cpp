#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> h(n);
		for(auto &hi : h) cin >> hi;
		
		int l=0, r=1e9+5;
		while(l+1 < r) {
			int m = l + (r-l)/2;
			bool can = true;
	
			vector<int> v(h);

			for(int i=n-1; i >= 2; i--) {
				int d = min(h[i]/3, max(0,(v[i]-m)/3));
				
				v[i] -= 3*d, v[i-1] += d, v[i-2] += 2*d;
			}
			
			for(int i=0; i < n; i++)
				can &= (v[i] >= m);
			
			if (can)
				l = m;
			else
				r = m;
		}
		
		cout << l << "\n";
	}
}