#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> c(n);
		for(auto &ci : c) cin >> ci;
		
		map<int, vector<int>> idx;
		map<int, multiset<int>> m;
		
		for(int i=0; i < n; i++) {
			if (m[c[i]].empty())
				m[c[i]].insert(i);
			else
				m[c[i]].insert(i - idx[c[i]].back() - 1);
				
			idx[c[i]].push_back(i);
		}
		
		for(int i=1; i <= k; i++) {
			if (!idx[i].empty())
				m[i].insert(n - idx[i].back() - 1);
		}

		auto get_min_needed = [&] (int x) -> int {
			int l=-1, r=n;
			
			while(l+1 < r) {
				int mid = l + (r-l)/2;
				
				if (mid == 0 && idx[x].size() >= n-1){
					r = mid;
					continue;
				} else if (mid == 0){
					l = mid;
					continue;
				}
				
				if (m[x].lower_bound(2*mid+2) != m[x].end())
					l = mid;
				else if (distance(m[x].upper_bound(mid), m[x].end()) >= 2)
					l = mid;
				else
					r = mid;
			}
			
			return r;
		};
		
		int ans = 1e9;
		
		for(int i=1; i <= k; i++) {
			if (!idx[i].empty())
				ans = min(ans, get_min_needed(i));
		}
		
		cout << ans << "\n";
	}
}