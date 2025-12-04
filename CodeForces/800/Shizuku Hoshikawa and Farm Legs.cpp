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
		
		if (n % 2) {
			cout << 0 << "\n";
			continue;
		}
		
		int ans = 0;
		
		for(int i=0; i <= n/2; i++) {
			
			if ((n - i*2) % 4 == 0)
				ans += 1;
		}
		
		cout << ans << "\n";
	}
}