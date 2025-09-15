#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int q;
	cin >> q;
	
	while(q--) {
		long long n, m, k;
		cin >> n >> m >> k;
		
		n = abs(n), m = abs(m);
		
		if (max(n, m) > k) {
			cout << -1 << "\n";
			continue;
		}
		
		bool diff = (n % 2 + m % 2) % 2;		
		long long r = k - (max(n, m) - 1);
		
		if (!diff) {
			cout << max(n, m) - 1 + (r % 2 ? r : r-2) << "\n";
		} else {
			cout << max(n, m) - 1 + r-1 << "\n";
		}
		
	}
}