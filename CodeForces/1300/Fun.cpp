#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		ll n, x;
		cin >> n >> x;
		
		ll ans = 0;
		
		for(ll a=1; a <= n; a++) {
			for(ll b=1; a*b <= n; b++) {
				ll c = min(x - a - b, (n - a*b) / (a + b));
				
				if (c > 0 && a + b + c <= x)
					ans += c;
			}
		}
		
		cout << ans << endl;
	}
}