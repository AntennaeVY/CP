#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		int n, m;
		cin >> n >> m;
		
		vector<int> a(n), b(m);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		a[0] = min(a[0], b[0] - a[0]);
		
		for(int i=1; i < n; i++) {
			int x = a[i];
			int y = b[0] - a[i];
			
			if (x >= a[i-1] && y >= a[i-1])
				a[i] = min(x, y);
			else
				a[i] = max(x, y);
		}
		
		bool can = true;
		
		for(int i=1; i < n; i++) {
			can &= a[i] >= a[i-1];
		}
		
		cout << (can ? "YES" : "NO") << endl;
	}
}