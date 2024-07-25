#include<bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

long long binpow(long long a, long long b) {
	a %= mod;
	
	long long r = 1;
	
	while(b) {
		if (b & 1)
			r = r * a % mod;
			
		a = a * a % mod;
		b >>= 1;
	}
	
	return r;
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long l, r, k;
		cin >> l >> r >> k;
		
		if (k > 9) {
			cout << 0 << endl;
			continue;
		}
		
		cout << (binpow(9/k + 1, r) - binpow(9/k + 1, l) + mod) % mod << endl;
	}
}