#include<bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		ll l, r;
		cin >> l >> r;
		
		int m = 0;
		while(l * (1 << (m + 1)) <= r)
			m++;
		
		cout << m+1 << " ";
		
		ll ans = (max(0LL, r/(1 << m) - l + 1)) % mod;
		
		if (m > 0)
			ans += (max(0LL, (r/(3LL * (1 << (m-1))) - l + 1)) % mod) * (1LL * m);
		
		ans %= mod;
		
		cout << ans << endl;
	}
}