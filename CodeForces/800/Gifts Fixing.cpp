#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		int target_a = *min_element(a.begin(), a.end());
		int target_b = *min_element(b.begin(), b.end());
	
		long long ans = 0;
		
		for(int i=0; i < n; i++) {
			ans += max(a[i] - target_a, b[i] - target_b);
		}
		
		cout << ans << endl;
	}
	
}