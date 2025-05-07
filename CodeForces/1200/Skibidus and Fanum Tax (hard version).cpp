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
		
		sort(b.begin(), b.end());
		
		a[0] = min(a[0], b[0] - a[0]);
		
		for(int i=1; i < n; i++) {
			auto it = lower_bound(b.begin(), b.end(), a[i] + a[i-1]);
		
			if (it != b.end())
				if (a[i] >= a[i-1])
					a[i] = min(a[i], *it - a[i]);
				else
					a[i] = *it - a[i];
		}
		
		bool can = true;
		
		for(int i=1; i < n; i++) {
			can &= a[i] >= a[i-1];
		}
		
		cout << (can ? "YES" : "NO") << endl;
	}
}