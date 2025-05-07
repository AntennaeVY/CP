#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<int> a(n), b(m);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		vector<int> first(m+1, 2e9 + 5), last(m+1, -1);
		
		first[0] = -1, last[0] = 2e9 + 5;
		
		for(int i=0, j=0; i < n; i++) {
			if (j < m && a[i] >= b[j])
				first[++j] = i;
		}
		
		for(int i=n-1, j=m-1; i >= 0; i--) {
			if (j > 0 && a[i] >= b[j])
				last[m-j] = i, j--;
		}
		
		// for(int i=0; i <= m; i++) {
			// cout << first[i] << " ";
		// }
		// cout << endl;
				// for(int i=0; i <= m; i++) {
			// cout << last[i] << " ";
		// }
		// cout << endl;
		
		if (first[m] != 2e9 + 5 || last[m] != -1) {
			cout << 0 << endl;
			continue;
		}
		
		int ans = 2e9+5;
		
		for(int i=1; i <= m; i++) {
			// cout << first[i-1] << " " << last[m-i] << endl;
			
			if (first[i-1] < last[m-i])
				ans = min(ans, b[i-1]);
		} 
		
		if (ans == 2e9 + 5)
			cout << -1 << endl;
		else
			cout << ans << endl;
		
	}
}