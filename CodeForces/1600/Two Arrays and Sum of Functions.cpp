#include<bits/stdc++.h>
using namespace std;

constexpr long long mod = 998244353;

int main() {
	int n;
	cin >> n;
	
	vector<int> a(n), b(n);
	for(auto &ai : a) cin >> ai;
	for(auto &bi : b) cin >> bi;
	
	vector<long long> c(n);
	for(int i=0; i < n; i++) {
		c[i] = 1LL * a[i] * (i+1) * (n-i);
	}
	
	sort(c.rbegin(), c.rend());
	sort(b.begin(), b.end());
	
	long long ans = 0;
	
	for(int i=0; i < n; i++) {
		ans += ((c[i] % mod) * (b[i] % mod)) % mod;
		ans %= mod;
	}
	
	cout << ans << endl;
}