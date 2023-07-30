#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		sort(a.begin(), a.end());
		
		if (count(a.begin(), a.end(), a[0]) == n) {
			cout << -1 << endl;
			continue;
		}
		
		int ans = 0;
		for(int i=1; i < n; i++) {
			ans = __gcd(ans, a[i] - a[0]);
		}
		
		cout << ans << endl;
	}
}