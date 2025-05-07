#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<long long> x(n), r(n);
		for(auto &xi : x) cin >> xi;
		for(auto &ri : r) cin >> ri;
		
		map<int, long long> mp;
		
		for(int i=0; i < n; i++) {
			long long st = x[i] - r[i];
			long long ed = x[i] + r[i];
			
			for(int j=st; j <= ed; j++) {
				long long sq = sqrtl(r[i]*r[i] - (x[i]-j)*(x[i]-j));
			
				mp[j] = max(mp[j], 2*sq + 1);
			}
		}
		
		long long ans = 0;
		for(auto &[j, c] : mp) {
			ans += c;
		}
		
		cout << ans << endl;
	}
}