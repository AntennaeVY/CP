#include<bits/stdc++.h>
using namespace std;

constexpr long long mod = 998244353;

int main() {
	int n;
	cin >> n;
	
	vector<long long> a(n);
	for(auto &ai : a) cin >> ai;
	
	map<int, int> cnt, at_least;
	for(int i=0; i < n; i++) {
		cnt[to_string(a[i]).size()]++;
	}
	
	for(int i=10; i >= 1; i--) {
		at_least[i] += at_least[i+1] + cnt[i];
	}

	long long ans = 0;
	
	for(int i=0; i < n; i++) {
		int x = a[i];
		int size = to_string(x).size();
		unsigned long long p = 1;
		
		for(int c=1; c <= size; c++) {
			long long d = x % 10;
			
			ans += at_least[c] * d * (p % mod) % mod;
			ans += at_least[c] * d * (p * 10 % mod) % mod; 
			ans %= mod;
			
			p *= 100, x /= 10;
		}
		
		x = a[i], p = 1;
		
		for(int j=1; j < size; j++) {
			x /= 10, p *= 100;
			
			ans += 2 * (cnt[j] * x % mod) * (p % mod);
			ans %= mod;
		}
	}
	
	cout << ans << endl;
}