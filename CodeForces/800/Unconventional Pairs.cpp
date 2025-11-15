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
		
		sort(a.begin(), a.end());
		
		int ans = 0;
		
		for(int i=1; i < n; i+=2) {
			ans = max(ans, a[i] - a[i-1]);
		}
		
		cout << ans << "\n";
	}
}