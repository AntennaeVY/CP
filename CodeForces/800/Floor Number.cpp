#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, x;
		cin >> n >> x;
		
		if (n == 1 || n == 2) {
			cout << 1 << endl;
			continue;
		}
		
		int ans = 2;
		
		for(int i=3; i <= n; i += x) {
			if (i + x > n)
				break;
				
			ans++;
		}
		
		cout << ans << endl;
	}
}