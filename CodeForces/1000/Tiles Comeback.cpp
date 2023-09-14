#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> c(n);
		for(auto &ci : c) cin >> ci;
		
		map<int, vector<int>> m;
		
		for(int i=0; i < n; i++) {
			m[c[i]].push_back(i);
		}
		
		if (c[0] == c[n-1] && m[c[0]].size() >= k) {
			cout << "YES" << endl;
			continue;
		} else if (m[c[0]].size() < k || m[c[n-1]].size() < k) {
			cout << "NO" << endl;
			continue;
		}
		
		int l = m[c[0]][k-1];
		int r = m[c[n-1]][m[c[n-1]].size() - k];
		
		if (r < l) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}
}