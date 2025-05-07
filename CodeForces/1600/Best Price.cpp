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
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		
		vector<int> v;
		for(auto &ai : a) v.push_back(ai);
		for(auto &bi : b) v.push_back(bi);
		
		long long ans = 0;
		
		for(int i=0; i < 2*n; i++) {
			long long buy = b.end() - lower_bound(b.begin(), b.end(), v[i]);
			long long good = a.end() - lower_bound(a.begin(), a.end(), v[i]);
		
			
			if (buy - good <= k)
				ans = max(ans, buy * v[i]);
				
			// cout << v[i] << " " << buy << " " << good << endl;
		}
		
		cout << ans << "\n";
	}
}