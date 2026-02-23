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
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int mn = *min_element(a.begin(), a.end());
		int ans = 1e9;
		
		for(int i=0; i < n; i++) {
			if (a[i] == mn)
				continue;
				
			ans = min(ans, a[i] - mn);
		}
		
		ans = max(ans, mn);
		
		
		cout << ans << "\n";
	}
}