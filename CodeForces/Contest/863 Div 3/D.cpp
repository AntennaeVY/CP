#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	long long f[45];
	f[0] = f[1] = 1;
	
	for(int i=2; i < 45; i++) {
		f[i] = f[i-1] + f[i-2];
	}
	
	while(t--) {
		long long n, x, y;
		cin >> n >> x >> y;
		
		bool ok = true;
		
		while(n > 1) {
			if(y > f[n-1] && y <= f[n])
				ok = false;
				
			if (y > f[n])
				y -= f[n];
				
			swap(x, y);
			n--;
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}