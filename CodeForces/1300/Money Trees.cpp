#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<int> h(n);
		for(auto &hi : h) cin >> hi;
		
		int l=0, ans = 0, cnt = 0; 
		
		for(int r=0; r < n; r++) {
			cnt += a[r];
			
			while(l < r && (cnt > k || h[max(r-1, 0)] % h[r])) {
				cnt -= a[l++];
			}
			
			if (cnt <= k)
				ans = max(ans, r-l+1);
		}
		
		cout << ans << endl;
	}
}