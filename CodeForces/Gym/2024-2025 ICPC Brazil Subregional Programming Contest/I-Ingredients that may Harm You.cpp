#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;
constexpr int MAXV = 1e6 + 5;

long long binpow(long long a, long long b) {
	long long ans = 1;
	
	a %= MOD;
	
	while(b) {
		if (b & 1) ans *= a, ans %= MOD;
		
		a *= a, a %= MOD;
		b >>= 1;
	}
	
	return ans;
}

vector<int> cnt(MAXV, 0);

int main() {
	int n;
	cin >> n;
	
	vector<int> v(n);
	for(auto &vi : v)
		cin >> vi;
		
	for(int i=0; i < n; i++) {
		cnt[v[i]]++;
		
		for (int j=2; j*j <= v[i]; j++) {
			if (v[i] % j)
				continue;
				
			cnt[j]++;
		
			if (j*j != v[i])
				cnt[v[i] / j]++;
		}
	}
	
	int q;
	cin >> q;
	
	while(q--) {
		int x;
		cin >> x;
		
		vector<int> p;
		
		for(int i=2; i*i <= x; i++) {
			if (x % i)
				continue;
				
			p.push_back(i);
			
			while(x % i == 0)
				x /= i;	
		}
		
		if (x > 1)
			p.push_back(x);
			
		int m = p.size();
		
		int ans = n;
		
		for(int i=1; i < (1 << m); i++) {
			int s = __builtin_popcount(i);
			int mult = 1;
				
			for(int j=0; j < m; j++) {
				if ((i >> j) & 1)
					mult *= p[j];	
			}
			
			if (s % 2)
				ans -= cnt[mult];
			else
				ans += cnt[mult];
		}
		
		cout << binpow(2, ans) << endl;
	}
}