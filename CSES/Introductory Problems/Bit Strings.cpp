#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

long long binpow(long long x, long long y) {
	long long ans = 1;
	x %= MOD;
	
	while(y) {
		if (y & 1)
			ans = (ans * x) % MOD;
			
		x = (x * x) % MOD;
		y >>= 1; 
	}
	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	cout << binpow(2, n) << endl;
}