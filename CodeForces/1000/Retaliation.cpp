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
		
		vector<long long> a(n+1);
		for(int i=1; i <= n; i++) {
			cin >> a[i];
		}
		
		if ((2*a[1] - a[2]) % (n+1)) {
			cout << "NO\n";
			continue;
		}
		
		long long y = (2*a[1] - a[2]) / (n+1); 
		long long x = a[1] - n*y;
		
		if (y < 0 || x < 0) {
			cout << "NO\n";
			continue;	
		}
		
		bool ok = true;
		for(int i=1; i <= n; i++) {
			ok &= ((a[i] - i*x - (n-i+1)*y) == 0);
		}
		
		cout << (ok ? "YES" : "NO") << "\n";
	}
}