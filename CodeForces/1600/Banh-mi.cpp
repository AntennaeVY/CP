#include<bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

long long binpow(long long a, long long b) {
    a %= mod;
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, q;
	cin >> n >> q;
	
	string s;
	cin >> s;
	
	vector<int> p(n+1, 0);
	
	for(int i=0; i < n; i++) {
		p[i+1] = p[i] + (s[i] - '0');
	}
	
	while(q--) {
		int l, r;
		cin >> l >> r;
		
		int x = p[r] - p[l-1];
		int y = r - l + 1 - x;
		
		cout << (binpow(2LL, x+y) - binpow(2LL, y) + mod) % mod << '\n';
	}
}