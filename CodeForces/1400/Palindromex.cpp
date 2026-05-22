#include<bits/stdc++.h>
using namespace std;

int calculate(int l, int r, map<int, pair<int,int>> &m, vector<int> &a) {
	bool is_odd = (r-l+1) % 2;
	
	bool bad = false;
	for(int i=l+1; i < r; i++) {
		int j=m[a[i]].first;
		int k=m[a[i]].second;
		
		if (is_odd && i == (l+r)/2)
			continue;
		
		if (j-l != r-k) {
			bad = true;
			break;
		}
	}
	
	if (bad)
		return 1;
	
	int nl = l, nr = r;
	
	for(int i=l-1; i >= 0; i--) {
		int j=m[a[i]].first;
		int k=m[a[i]].second;
		
		if (l-j == k-r) {
			nl--, nr++;
		} else {
			break;
		}
	}
	
	vector<bool> has(1e5+5);
	for(int i=nl; i <= nr; i++) {
		has[a[i]] = true;
	}
	
	
	for(int i=0; i < has.size(); i++) {
		if (!has[i]) {
			return i;
		}
	}
	
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(2*n);
		for(auto &ai : a) cin >> ai;
		
		map<int, pair<int,int>> m;
		for(int i=0; i < 2*n; i++) {
			if (m.find(a[i]) == m.end()) {
				m[a[i]] = {i, -1};
			} else {
				m[a[i]].second = i;
			}
		}
				
		int l=m[0].first, r=m[0].second;
		
		int ans = calculate(l, r, m, a);
		ans = max(ans, calculate(l, l, m, a));
		ans = max(ans, calculate(r, r, m, a));
		
		cout << ans << "\n";
	}
}