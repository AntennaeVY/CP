#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		int ans = 0;
		
		if (n % 2) {
			if (k % 2)
				n -= k, ans++;
			else
				n -= (k-1), ans++;
		}
		
		if (k % 2)
			ans += (n+k-2) / (k-1);
		else
			ans += (n + k-1)/ k;
			
		cout << ans << endl;
	}
}