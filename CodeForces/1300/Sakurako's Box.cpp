#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long n;
		cin >> n;
		
		vector<long long> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<long long> p(n+1);
		for(int i=0; i < n; i++)
			p[i+1] = p[i] + a[i], p[i+1] %= MOD;
	
		long long ans = 0;
		
		for(int i=0; i < n; i++) {
			ans += 1LL * a[i] * ((p[n] - p[i+1] + MOD) % MOD);
			
			ans %= MOD;
		}
		
		long long x = 2LL * binpow(1LL*n*(n-1), MOD-2, MOD);
		
		ans *= x, ans %= MOD;
		
		cout << ans << endl;
	}
}