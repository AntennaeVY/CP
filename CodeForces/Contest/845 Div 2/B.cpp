#include<bits/stdc++.h>
using namespace std;

constexpr int mod = 1'000'000'007;

long long factmod(long long x) {	
	long long ans = 1;
	
	for(int i=x; i > 1; i--) {
		ans *= i;
		ans %= mod;
	}
	
	return ans;
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		cout << (((factmod(n) * n) % mod) * (n - 1)) % mod << endl;
	}
}