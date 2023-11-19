#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<string> a(n);
		for(auto &ai : a) cin >> ai;
		
		// (i, j) -> (j, n-i-1)
		// (j, n-i-1) -> (n-i-1, n-j-1)
		// (n-i-1, n-j-1) -> (n-j-1, i)
		// (n-j-1, i) -> (i, j)
		
		int ans = 0;
		
		for(int i=0; i*2 < n; i++) {
			for(int j=0; j*2 < n; j++) {
				vector<char> s = {a[i][j], a[j][n-i-1], a[n-i-1][n-j-1], a[n-j-1][i]};
				
				sort(s.rbegin(), s.rend());
				
				for(auto c : s) 
					ans += s[0] - c;
			}
		}
		
		cout << ans << endl;
	}
}