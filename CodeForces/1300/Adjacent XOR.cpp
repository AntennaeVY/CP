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
		
		int s = 0;
		bool ok = true;
		
		for(int i=n-1; i >= 0; i--) {
			if ((a[i] ^ s) == b[i]) {
				s ^= a[i];
				continue;
			}
			
			if (a[i] == b[i]) {
				s = 0;
				continue;
			}
			
			if (i+1 < n && (a[i] ^ a[i+1]) == b[i]) {
				s = a[i] ^ a[i+1];
				continue;
			}
			
			ok = false;
		}
		
		cout << (ok ? "YES" : "NO") << "\n";
	}
}