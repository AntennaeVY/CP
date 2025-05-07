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
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		bool can = true;
		int x = -1;
		
		for(int i=0; i < n; i++) {
			if (b[i] != -1)
				x = a[i] + b[i];
		}
		
		if (x != -1) {
			for(int i=0; i < n; i++) {
				if (b[i] != -1)
					can &= (a[i] + b[i] == x);
				else
					can &= (x - a[i] >= 0 && x - a[i] <= k);
			}
		}
		
		if (!can) {
			cout << 0 << endl;
			continue;
		}
		
		if (x != -1) {
			cout << 1 << endl;
			continue;
		}
		
		int mn = -1, mx = 2e9 + 5;
		for(int i=0; i < n; i++) {
			mn = max(mn, a[i]);
			mx = min(mx, a[i] + k);
		}
		
		if (mn > mx)
			cout << 0 << endl;
		else
			cout << mx - mn + 1 << endl;
	}
}