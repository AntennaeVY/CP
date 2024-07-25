#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long n, m;
		cin >> n >> m;
		
		map<long long, long long> cnt;
		
		for(int i=0; i < n; i++) {
			long long x;
			cin >> x;
			
			cnt[x]++;
		}
		
		long long ans = 0;
		
		for(auto [k, c] : cnt) {
			for(int i=1; i <= c; i++) {
				long long x = min(m, i * k) / k;
				long long y = min(m - x*k, (k+1) * cnt[k+1]) / (k+1);
				
				ans = max(ans, x*k + y*(k+1));
			}
		}
		
		cout << ans << endl;
	}
}