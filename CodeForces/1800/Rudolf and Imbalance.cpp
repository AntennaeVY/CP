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
		
		vector<int> a(n), d(m), f(k);
		for(auto &ai : a) cin >> ai;
		for(auto &di : d) cin >> di;
		for(auto &fi : f) cin >> fi;
		
		sort(d.begin(), d.end());
		sort(f.begin(), f.end());
		
		int ans = 0, cnt = 0, j = -1;
		for(int i=1; i < n; i++) {
			if (a[i] - a[i-1] > ans) {
				ans = a[i] - a[i-1];
				cnt = 1;
				j = i;
			} else if (a[i] - a[i-1] == ans) {
				cnt++;
			}
		}
		
		if (cnt >= 2) {
			cout << ans << "\n";
			continue;
		}
		
		vector<int> diffs;
		for(int i=1; i < n; i++) {
			if (a[i] - a[i-1] != ans)
				diffs.push_back(a[i] - a[i-1]);
		}
		
		long long x = (0LL + a[j] + a[j-1])/2;
		
		for(int i=0; i < m; i++) {
			int z = lower_bound(f.begin(), f.end(), x - d[i]) - f.begin();
			
			if (z <= k-1 && d[i] + f[z] >= a[j-1] && d[i] + f[z] <= a[j])
				ans = min(ans, max(d[i] + f[z] - a[j-1], a[j] - d[i] - f[z]));
			
			if (z > 0 && d[i] + f[z-1] >= a[j-1] && d[i] + f[z-1] <= a[j])
				ans = min(ans, max(d[i] + f[z-1] - a[j-1], a[j] - d[i] - f[z-1]));
			
			if (z < k-1 && d[i] + f[z+1] >= a[j-1] && d[i] + f[z+1] <= a[j])
				ans = min(ans, max(d[i] + f[z+1] - a[j-1], a[j] - d[i] - f[z+1]));
		}
		
		diffs.push_back(ans);
		
		cout << *max_element(diffs.begin(), diffs.end()) << "\n";
	}
}