#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		int ans = 1e9;
		
		for(int i=1; i*i <= n; i++) {
			if (n % i == 0 && i <= k)
				ans = min(ans, n/i);
			
			if (n % i == 0 && n/i <= k)
				ans = min(ans, i);
		}
		
		cout << ans << endl;
	}
}