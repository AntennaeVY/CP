#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long n, a, b;
		cin >> n >> a >> b;
		
		if (b == 1) {
			cout << "YES" << endl;
			continue;
		}
	
		if (a == 1 && n % b != 1) {
			cout << "NO" << endl;
			continue;
		}
		
		long long x = 1;
		bool ok = false;
		
		while(x <= n) {
			if ((n - x) % b == 0) {
				ok = true;
				break;
			}
			
			x *= a;
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}