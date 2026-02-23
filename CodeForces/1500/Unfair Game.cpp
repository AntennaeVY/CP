#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;
vector<long long> fact(33);

long long binpow(long long x, long long m) {
	if (m == 0)
		return 1;
		
	if (m % 2 == 0) {
		long long res = binpow(x, m/2);
		return (res * res) % MOD;
	}
		
	return (x * binpow(x, m-1)) % MOD;
}

long long modinv(long long a) {
	return binpow(a, MOD-2);
}

long long nchoosek(long long n, long long k) {
	return (fact[n] * modinv((fact[k] * fact[n-k]) % MOD)) % MOD; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	fact[0] = 1;
	for(int i=1; i <= 32; i++) {
		fact[i] = (1LL * i * fact[i-1]) % MOD;
	}
		
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		int cnt = 0;
		
		while(n) {
			cnt += 1;
			n /= 2;	
		}
		
		int ans = 0;
		
		for(int i=0; i < 32; i++) {
			for(int j=0; j < 32; j++) {
				if (i + j + 1 >= cnt)
					continue;
					
				if (2*i + j + 1 > k) {
					ans += nchoosek(i+j, i);
				}
			}
		}
		
		if (cnt > k)
			ans += 1;
			
		cout << ans << "\n";
	}
}