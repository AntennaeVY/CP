#include<bits/stdc++.h>
using namespace std;

constexpr long long mod = 998244353;

int main() {
	int n;
	cin >> n;
	
	vector<long long> a(n);
	for(auto &ai : a) cin >> ai;
	
	long long ans = 0;
	
	for(int i=0; i < n; i++) {
		unsigned long long p = 1;
		
		while(a[i]) {
			int d = a[i] % 10;
			
			ans += (n*d % mod) * (p % mod) + (n*d*10 % mod) * (p % mod);
			ans %= mod;
			
			p *= 100, a[i] /= 10;
		}
	}
	
	cout << ans << endl;
}