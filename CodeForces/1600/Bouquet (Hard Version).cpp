#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long n, m;
		cin >> n >> m;
		
		vector<long long> p(n), q(n);
		for(auto &pi : p) cin >> pi;
		for(auto &qi : q) cin >> qi;
		
		map<long long, long long> cnt;
		
		for(int i=0; i < n; i++) {
			cnt[p[i]] = q[i];
		}
		
		long long ans = 0;
		
		for(auto [k, c] : cnt) {
			ans = max(ans, k * (min(m, k*c) / k));
			
			if (cnt.find(k+1) == cnt.end())
				continue;
			
			long long current = m;
			
			long long x = min(current / k, c);
			
			current -= x * k;
			
			long long y = min(current / (k+1), cnt[k+1]);
			
			current -= y * (k+1);
			
			long long add = min({x, cnt[k+1] - y, current});
			
			ans = max(ans, (x-add)*k + (y+add)*(k+1));
		}
		
		cout << ans << endl;
	}
}