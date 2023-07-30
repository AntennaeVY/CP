#include<bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

int n_choose_k_mod(int n, int k) {
	int num = 1, den = 1;
	
	for(int i=n; i > n-k; i--) {
		num = (1LL * num * i) % mod;
	}
	
	for(int i=2; i <= k; i++) {
		den = (1LL * den * i) % mod;
	} 

	int r = 1, p = mod - 2;
	
	while(p) {
		if (p & 1) 
			r = (1LL * r * den) % mod;
		
		p >>= 1;
		den = (1LL * den * den) % mod;
	}
	
	return (1LL * num * r) % mod;

}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;

		sort(a.begin(), a.end());
		
		long long ans = 0;
		int l=0;
		
		for(int r=0; r < n; r++) {
			while(a[r] - a[l] > k && r-l+1 > m) 
				l++;
				
			if (a[r] - a[l] <= k && r-l+1 >= m) 
				ans = (ans + n_choose_k_mod(r-l, m-1)) % mod;
		}
		
		cout << ans << endl;
	}
}