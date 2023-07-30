#include<bits/stdc++.h>
using namespace std;

using ll = long long;

set<long long> s;

int main() {
	int t;
	cin >> t;
	
	for(ll i=2; i <= 1e6; i++) {
		ll sum = 1 + i, p = i*i;
		
		for(ll j=2; j <= 64; j++) {
			sum += p;
			s.insert(sum);
			
			if (p > 1e18 / i)
				break;
			
			p *= i;
		}
	}
	
	while(t--) {
		ll n;
		cin >> n;
		
		if (n <= 6) {
			cout << "NO" << endl;
			continue;
		}
		
		ll x = floor(sqrt(n-1));
		
		if (x * (x+1) == n - 1 || x * (x-1) == n - 1 || s.count(n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}