#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		vector<long long> p(n+1, 0);
		for(int i=0; i < n; i++) {
			p[i+1] = p[i] + a[i];
		}
		
		long long ans = 0, mx = 0;
		
		for(int i=0; i < min(k, n); i++) {
			mx = max(mx, b[i]);
			
			ans = max(ans, p[i+1] + mx * (k-i-1));
		}
		
		cout << ans << "\n";
	}
}