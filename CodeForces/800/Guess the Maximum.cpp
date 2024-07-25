#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int ans = 1e9+1;
		
		for(int i=0; i < n-1; i++) {
			ans = min(ans, max(a[i], a[i+1]) - 1);
		}
		
		cout << ans << endl;
	}
}