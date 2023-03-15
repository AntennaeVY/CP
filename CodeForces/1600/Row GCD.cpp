#include<bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	a = abs(a), b = abs(b);
	
	if (b > a)
		swap(a,b);
	
	while(b != 0) {
		a %= b;
		swap(a, b);
	}
	
	return a;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<ll> a(n), b(m);
	for(auto &ai : a) cin >> ai;
	for(auto &bi : b) cin >> bi;
	
	if (n == 1) {
		for(auto x : b) 
			cout << a[0] + x << " ";
		
		return 0;
	}
	
	ll r = a[1] - a[0];
	for(auto x : a)
		r = gcd(r, x - a[0]);
		
	for(auto x : b) {
		cout << gcd(a[0] + x, r) << " ";
	}
}