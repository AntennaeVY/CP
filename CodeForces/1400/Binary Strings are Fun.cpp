#include<bits/stdc++.h>
using namespace std;

constexpr long long mod = 998244353;

long long binPowMod(long long x, long long exp) {
	if (exp == 0)
		return 1;
	
	if (exp%2 == 0)
		return (binPowMod(x, exp/2) * binPowMod(x, exp/2)) % mod;
	else 
		return (x * binPowMod(x, exp-1)) % mod;
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		long long exp = 0;
		long long ans = 1;
		
		for(int i=1; i < n; i++) {
			if (s[i] == s[i-1])
				exp++;
			else
				exp = 0;
				
			ans = (ans % mod + binPowMod(2, exp) % mod) % mod;
		}
		
		cout << ans << endl;
	}
}