#include<bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9+7;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long n;
		cin >> n;
		
		long long ans = 0;
		
		if (n%3 != 2) {
			ans = n*(n-1)/3 % mod;
			ans *= (2*(n-1)+1) % mod;
		} else {
			ans = (2*(n-1)+1)/3 % mod;
			ans *= n*(n-1) % mod;
		}
			
		ans %= mod;
		
		ans += (n*(n-1)/2) % mod;
		ans %= mod;
		
		ans += (n*n)%mod;
		ans %= mod;
		 
		cout << (2022 * ans)%mod << endl;
	}
}