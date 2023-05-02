#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main() {
	int t;
	cin >> t;
	
	while(t--) {
		ll n, k;
		cin >> n >> k;
		
		ll sum = 0, mn = 1e9;
		vector<int> a(n);
		
		for(auto &ai : a) {
			cin >> ai;
			sum += ai;
			
			mn = min(mn, 1LL*ai);
		}
		
		if (sum <= k) {
			cout << 0 << endl;
			continue;
		}
		
		sort(a.rbegin(), a.rend());
		
		vector<ll> p(n+1, 0);
		for(int i=0; i < n; i++) {
			p[i+1] = p[i] + a[i];
		}
			
		ll ans = sum - k; 
		
		for(ll i=0; i < n; i++) {
			ll x = sum - p[i] + mn*i;
			
			ans = min(ans, i + (max(x - k, 0LL) + i) / (i+1));	
		}
		
		cout << ans << endl;
 	}
}