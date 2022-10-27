#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int ans = 1, l = 1, r = 1;
		
		while(r <= n) {
			ans = max(ans, r-l);
			l = r;
			r <<= 1;
		}
	
		if (r != n)
			ans = max(ans, n-l+1);
		
		cout << ans << endl;
	}
}