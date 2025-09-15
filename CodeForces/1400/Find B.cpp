#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n,q;
		cin >> n >> q;
		
		vector<int> c(n);
		for(auto &ci : c) cin >> ci;
		
		vector<long long> p(n+1, 0);
		
		for(int i=0; i < n; i++) {
			p[i+1] = p[i] + (c[i] > 1 ? c[i] : 0);
		}
		
		while(q--) {
			int l, r;
			cin >> l >> r;
			
			l--, r--;
		
			if (l == r) {
				cout << "NO\n";
			} else {
				if (p[r+1] - p[l] - (r-l) > 0)
					cout << "YES\n";
				else
					cout << "NO\n";
			}
		}
	}
}