#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		
		vector<int> a(n), b(m);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		
		int ans = 0;
			
		for(int i=0; i < m; i++) {
			auto it = prev(upper_bound(a.begin(), a.end(), k - b[i]));
			ans += it - a.begin() + 1;
		}
	
		cout << ans << "\n";
	}
}