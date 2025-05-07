#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		vector<int> ma(n+1), mb(n+1);
		for(int i=0; i < n; i++) {
			ma[a[i]] = i;
			mb[b[i]] = i;
		}
		
		int cnt = 0;
		
		for(int i=0; i < n; i++) {
			cnt += (ma[b[i]] == mb[a[i]]);
		}
		
		if (cnt != n) {
			cout << -1 << endl;
			continue;
		}
		
		vector<pair<int,int>> ans;
		
		for(int i=0; i < n/2; i++) {
			if (mb[a[i]] == i) {
				ans.push_back({i+1, (n/2) + 1});
				
				swap(a[i], a[n/2]);
				swap(b[i], b[n/2]);
				
				ma[a[n/2]] = n/2;
				mb[b[n/2]] = n/2;
				
				ma[a[i]] = i;
				mb[b[i]] = i;
			
			} else {
				int j = mb[a[i]];

				if (j == n-i-1)
					continue;
				
				ans.push_back({j+1, n-i});
				
				swap(a[j], a[n-i-1]);
				swap(b[j], b[n-i-1]);
			
				ma[a[n-i-1]] = n-i-1;
				mb[b[n-i-1]] = n-i-1;
				
				ma[a[j]] = j;
				mb[b[j]] = j;
		
			}
		}
		
		bool can = true;
		
		for(int i=0; i < n; i++) {
			can &= (a[i] == b[n-i-1]);
		}
// 		
		// for(int i=0; i < n; i++) {
			// cout << a[i] << " ";
		// }
		// cout << endl;
		// for(int i=0; i < n; i++) {
			// cout << b[i] << " ";
		// }
		// cout << endl;
// 		
		if (!can) {
			cout << -1 << endl;
			continue;
		}
		
		cout << ans.size() << endl;
		
		for(auto &ansi : ans) {
			cout << ansi.first << " " << ansi.second << endl;
		}
	}
}