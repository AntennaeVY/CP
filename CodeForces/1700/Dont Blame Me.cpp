#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		vector<vector<ll>> m(n+1, vector<ll>(64, 0));
		
		for(int j=1; j <= n; j++) {
			for(int i=0; i <= 63; i++) {
					m[j][i] += m[j-1][i];
					m[j][i] %= mod;
						
					m[j][a[j-1]&i] += m[j-1][i];
					m[j][a[j-1]&i] %= mod;
			}
			
			m[j][a[j-1]] += 1;
			m[j][a[j-1]] %= mod;
		}
		
		int ans = 0;
		
		for(int i=0; i <= 63; i++) {
			if (__builtin_popcount(i) == k)
				ans += m[n][i];
			
			ans %= mod;
		}
		
		cout << ans << endl;
	}
}