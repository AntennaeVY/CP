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
		
		vector<int> p(n), s(n);
		for(auto &pi : p) cin >> pi;
		for(auto &si : s) cin >> si;
		
		vector<long long> a(n);
		a[0] = p[0], a[n-1] = s[n-1];
		
		for(int i=1; i < n-1; i++) {
			a[i] = 1LL * p[i] * s[i] / __gcd(p[i], s[i]);
		}
		
		bool ok = true;
		
		long long gcd = a[0];
		for(int i=1; i < n; i++) {
			ok &= (__gcd(a[i], gcd) == p[i]);
			gcd = __gcd(a[i], gcd);
		}
		
		gcd = a[n-1];
		for(int i=n-2; i >= 0; i--) {
			ok &= (__gcd(a[i], gcd) == s[i]);
			gcd = __gcd(a[i], gcd);
		}
		
		if (n == 1) {
			ok &= (p[0] == s[0]);
		}
		
		cout << (ok ? "YES" : "NO") << "\n";
	}
	
}