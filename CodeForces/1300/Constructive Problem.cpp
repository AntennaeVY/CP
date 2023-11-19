#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		map<int, int> cnt;
		map<int, pair<int, int>> idx;
		
		for(int i=0; i < n; i++) {
			cnt[a[i]]++;
			
			if (idx.find(a[i]) == idx.end())
				idx[a[i]].first = 1e9, idx[a[i]].second = -1;
				
			idx[a[i]].first = min(idx[a[i]].first, i);
			idx[a[i]].second = max(idx[a[i]].second, i);
		}
		
		int mex = 2e5 + 1;
		
		for(int i=0; i <= 2e5; i++) {
			if (cnt.find(i) == cnt.end()) {
				mex = i;
				break;
			}
		}
		
		if (mex == 2e5 + 1) {
			cout << "NO" << endl;
			continue;
		}
		
		if (cnt[mex + 1] == 0) {
			bool can = false;
			
			for(auto &[x, y] : cnt) {
				can |= (x > mex + 1 || y > 1);
			}
			
			cout << (can ? "YES" : "NO") << endl;
			continue;
		}
		
		bool ok = true;
		
		int l = idx[mex + 1].first, r = idx[mex + 1].second;
		
		for(auto &[k, p] : idx) {
			if (k >= mex + 1)
				continue;
			
			ok &= (p.first < l || p.second > r);
		}
		
		cout << (ok ? "YES" : "NO") << endl;

	}
}