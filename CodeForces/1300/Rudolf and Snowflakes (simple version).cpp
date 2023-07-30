#include<bits/stdc++.h>
using namespace std;

long long pow(long long x, int m) {
	long long ans = 1;
	
	while(m) {
		if (x & 1)
			ans *= x;
			
		m >>= 1;
		x *= x;
	}
	
	return ans;
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		if (n <= 6) {
			cout << "NO" << endl;
			continue;
		}
		
		bool ok = false;
		
		for(int i=2; i <= 1e5; i++) {
			if (i*i + i + 1 > n)
				break;
			
			for(int j=3; j <= 30; j++) {
				long long c = pow(i, j);
				long long d = (c-1) / (i-1);
				
				if (d > n)
					break;
				
				if ((c-1) % (i-1) == 0 && d == n)
					ok = true;
			}
			
			if (ok)
				break;
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}