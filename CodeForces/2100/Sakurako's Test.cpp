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
		
		vector<int> ans(n+1, 0), pref(2*n+1, 0);
		for(int i=0; i < n; i++) {
			pref[a[i]] += 1;
		}
		
		for(int i=1; i <= 2*n; i++) {
			pref[i] += pref[i-1];
		}
		
		for(int i=1; i <= n; i++) {
			int l=-1, r=i-1;
			
			while(l+1 < r) {
				int m = l + (r-l)/2;
				
				int cnt = 0;
				
				for(int j=0; j <= n; j+=i) {
					int tot = pref[j+i-1];
					
					if (j > 0)
						tot -= pref[j-1];
					
					tot -= pref[j+i-1] - pref[j+m];
					cnt += tot;
				}
				
				if (cnt >= n/2 + 1)
					r = m;
				else
					l = m;
			}
			
			ans[i] = r;
		}
		
		while(q--) {
			int x;
			cin >> x;
			
			cout << ans[x] << " ";
		}
		
		cout << endl;
	}
}