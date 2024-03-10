#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<long long> p(n+1, 0);
		for(int i=0; i < n; i++) {
			p[i+1] = p[i] + a[i];
		}
		
		long long ans = 0;
		
		for(int i=1; i <= n; i++) {
			if (n % i)
				continue;
			
			long long mn = p[n], mx = p[0];
			
			for(int j=i; j <= n; j+=i) {
				mn = min(mn, p[j] - p[j-i]);
				mx = max(mx, p[j] - p[j-i]);
			}
			
			ans = max(ans, mx - mn);
		}
		
		cout << ans << endl;
	}
}