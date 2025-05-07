#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, x;
		cin >> n >> x;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		sort(a.rbegin(), a.rend());
		
		int ans = 0;
	
		int l=0, r=0;
		while(r < n) {
			long long mn = a[l];
			
			while(r < n) {
				if (mn * (r-l+1) >= x)
					break;
					
				r++;
				mn = min(mn, 1LL * a[r]);
			}
			
			if (r < n && mn * (r-l+1) >= x) {
				// cout << mn << " " << l << " " << r << endl;
				
				ans++, r++;
				l = r;
			}
		}
		
		// for(auto &ai : a)
			// cout << ai << " ";
		// cout << endl;
		
		cout << ans << endl;
	}
}