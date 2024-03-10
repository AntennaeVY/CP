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
		
		vector<long long> a(n), b(n), p(n+1);
		for(int i=0; i < n; i++) {
			cin >> a[i] >> b[i];
		}
		
		for(int i=0; i < n; i++) {
			p[i+1] = p[i] + max(0LL, a[i] - b[(n+i-1) % n]);
		}
		
		long long ans = 1e18;
		
		for(int i=1; i <= n; i++) {
			ans = min(ans, a[i-1] + (p[n] - p[i]) + (p[i-1] - p[0]));
		}
		
		cout << ans << '\n';
	}
}