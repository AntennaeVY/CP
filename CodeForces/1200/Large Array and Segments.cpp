#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		long long n, k, x;
		cin >> n >> k >> x;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<long long> p(n+1), s(n+1);
		
		for(int i=0; i < n; i++) {
			p[i+1] = p[i] + a[i];
		}
		
		for(int i=n; i > 0; i--) {
			s[i-1] = s[i] + a[i-1];
		}
		
		long long sum = p[n];
		
		if (sum * k < x) {
			cout << 0 << endl;
			continue;
		} 
		
		long long ans = 0;
		long long m = x / sum;
		
		for(int i=1; i <= n; i++) {
			long long need = x - (s[i] + m * sum);
			int j = lower_bound(p.begin(), p.end(), need) - p.begin();
			
			long long cnt = (n-i) + m*n + j;
			
			if (cnt > n*k)
				continue;
			
			long long l = -1, r = 1e6;
			while(l + 1 < r) {
				long long q = l + (r-l) / 2;
				
				if (i % n + cnt + q*n <= n*k)
					l = q;
				else
					r = q;
			}
			
			
			ans += l+1;
		}
		
		cout << ans << endl;
	}
}