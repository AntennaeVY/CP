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
		
		k--;
		
		vector<int> h(n);
		for(auto &hi : h) cin >> hi;
				
		set<int> s;
		
		for(int i=0; i < n; i++) {
			if (h[i] > h[k])
				s.insert(h[i]);
		}
		
		bool can = true;
		int l = 1, hi = h[k];
		
		for(auto hj : s) {
			if (l + hj - 2*hi > 1)
				can = false;
				
			l += (hj-hi);
			hi = hj;
		}
		
		cout << (can ? "YES" : "NO") << endl;
	}
}