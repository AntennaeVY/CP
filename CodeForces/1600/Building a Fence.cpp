#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> h(n);
		for(auto &hi : h) cin >> hi;

		bool ok = true;
		int mn = h[0], mx = h[0];
		
		for(int i=1; i < n; i++) {			
			mn = max(mn - (k-1), h[i]);
			mx = min(mx + (k-1), h[i] + (k-1));
			
			if (mn > mx)
				ok = false;
		}
		
		if (h[n-1] < mn || h[n-1] > mx)
			ok = false;
		
		cout << (ok ? "YES" : "NO") << endl;
		
	}
}