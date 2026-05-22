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
		
		int x, y;
		cin >> x >> y;
		
		int k;
		cin >> k;
		
		int a = (x-y + n) % n;
		int b = (y-x + n) % n;
		
		if (n <= 3) {
			cout << 1 << "\n";
			continue;
		}

	 	int ans = min(a, b) - 1;
		
		cout << ans + k + 1 << "\n";
	}
}