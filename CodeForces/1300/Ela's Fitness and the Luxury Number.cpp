#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll squareRoot(ll x) {
	ll l = 1, r = 1e9+1;
	
	while(l+1 < r) {
		ll mid = l + (r-l)/2;
		
		if (mid*mid <= x)
			l=mid;
		else 
			r=mid;
	}
	
	return l;
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		ll l, r;
		cin >> l >> r;
		
		ll lsqrt = squareRoot(l), rsqrt = squareRoot(r);
		ll ans = max(3*(rsqrt - lsqrt - 1), 0LL);
		
		for(ll i = lsqrt*lsqrt; i < min((lsqrt+1)*(lsqrt+1), r+1); i+=lsqrt) {
			if (i >= l)
				ans++;
		}
		
		for(ll i = rsqrt*rsqrt; i <= r; i+=rsqrt) {
			if (lsqrt != rsqrt)
				ans++;
		}
		
		cout << ans << endl;
	}
}