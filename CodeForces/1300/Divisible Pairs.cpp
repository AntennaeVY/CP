#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, x, y;
		cin >> n >> x >> y;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		map<int, vector<int>> my;
		
		for(int i=0; i < n; i++) {
			my[a[i] % y].push_back(a[i]);
		}
		
		long long ans = 0;
		
		for(auto &[_, v] : my) {
			long long cnt = 0;
			map<int, int> mx;
			
			for(int i=0; i < v.size(); i++) {
				mx[v[i] % x]++;
			}
			
			for(auto &[m, c] : mx) {
				if (m == (x-m) % x)
					cnt += 1LL*(c)*(c-1);
				else
					cnt += 1LL*(c)*(mx[(x-m) % x]);
			}
			
			ans += cnt/2;
		}
		
		cout << ans << "\n";
	}
}