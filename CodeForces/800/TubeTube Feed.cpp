#include<bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	
	while(q--) {
		int n, t;
		cin >> n >> t;
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		int ans = -1, mx = 0;
		
		for(int i=0; i < n; i++) {
			if (a[i] <= t - i && b[i] > mx) 
				ans = i+1, mx = b[i];
		}
		
		cout << ans << endl;
	}
}