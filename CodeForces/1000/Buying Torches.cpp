#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		long long x, y, k;
		cin >> x >> y >> k;

		long long ans = (k*y + k - 1 + x - 2) / (x - 1) + k;
		
		cout << ans << endl;
	}
}