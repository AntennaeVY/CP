#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		long long ans = 0;
		
		for(int i=m; i < n; i++) {
			ans += min(a[i], b[i]);
		}
		
		long long sum = 0, end = 1e18;
		
		for(int i=m-1; i >= 0; i--) {
			end = min(end, sum + a[i]);
			sum += b[i];
		}
		
		ans += end;
		
		cout << ans << endl;
	}
}