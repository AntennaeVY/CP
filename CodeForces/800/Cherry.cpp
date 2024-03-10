#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<long long> a(n);
		for(auto &ai : a) cin >> ai;
		
		long long ans = 0;
		
		for(int i=1; i < n; i++) {
			ans = max(ans, a[i] * a[i-1]);
		}
		
		cout << ans << endl;
	}
}