#include<bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

long long binpow(long long a, long long b) {
    long long res = 1;
    
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}


int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		int bits = 0;
		
		while(m--) {
			int l, r, x;
			cin >> l >> r >> x;
			
			bits |= x;
		}
		
		cout << (1LL * bits * binpow(2, n-1)) % mod << endl;
	}
}