#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

long long binpow(long long a, long long b) {
	a %= MOD;
	
	long long res = 1;
	
	while(b) {
		if (b & 1)
			res *= a, res %= MOD;
			
		a *= a, a %= MOD;
		b >>= 1;
	}
	
	return res;
}

int main() {
	long long x, n;
	cin >> x >> n;
	
	long long ans = 1;
	
	vector<int> primes;
	
	for(long long i=2; i*i <= x; i++) {
		if (x % i)
			continue;
			
		while(x % i == 0)
			x /= i;
			
		primes.push_back(i);
	}
	
	if (x != 1)
		primes.push_back(x);
	
	for(auto p : primes) {
		long long acc = p;
	
		long long cnt = 0, q = n;
		while(q > 1)
			q /= p, cnt++;
		
		long long sum = 0, k = n/p;
	
		for(int i=1; i <= cnt; i++) {
			sum += k;
			k /= p;
		}
		
		ans *= binpow(p, sum);
		ans %= MOD;
	}
	
	cout << ans << endl;
}