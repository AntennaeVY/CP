#include<bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5 + 5;

bitset<MAXN> is_prime;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	is_prime.set();
	is_prime[0] = is_prime[1] = 0;
	
	for(long long i=2; i < MAXN; i++) {
		if (!is_prime[i])
			continue;
			
		for(long long j=i*i; j < MAXN; j+=i) {
			is_prime[j] = 0;
		}
	}
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> ans(n+1);
		ans[1] = 1;
		
		map<int, vector<int>> m;

		for(int i=n; i > 1; i--) {
			int p = 0;
			
			for(int j=2; j*j <= i; j++) {
				if (i % j != 0)
					continue;
				
				if (is_prime[j])
					p = max(p, j);
					
				if (is_prime[i/j])
					p = max(p, i/j);
			}
			
			if (!p)
				p = i;
				
			m[p].push_back(i);
		}
		
		for(auto &[p, v] : m) {
			int size = v.size();
			
			for(int i=0; i < size; i++) {
				ans[v[i]] = v[(i+1) % size];
			}
		}
		
		for(int i=1; i <= n; i++) {
			cout << ans[i] << " ";
		}
		
		cout << "\n";
	}
}