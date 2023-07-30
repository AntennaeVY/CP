#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n);
		for(auto &ai:a) cin >> ai;
		for(auto &bi:b) cin >> bi;
		
		bool ok = true;
		int maxd = 0;
		
		for(int i=0; i < n; i++) {
			if (a[i] - b[i] < 0)
				ok = false;
			
			maxd = max(a[i]-b[i], maxd);
		}
		
		for(int i=0; i < n; i++) {
			if (a[i] - maxd > b[i] || a[i] - maxd < b[i] && b[i] != 0)
				ok = false;
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}