#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, d;
		cin >> n >> d;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		sort(a.begin(), a.end());
		
		bool ok = true;
		
		for(int i=0; i < n; i++) {
			ok &= (a[i] <= d || a[0] + a[1] <= d);
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}