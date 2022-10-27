#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		int gcd = a[0];
		
		for(int i=1; i < n; i++) {
			gcd = __gcd(gcd, a[i]);
		}
		
		if (gcd == 1) {
			cout << 0 << endl;
			continue;
		}
		
		if (n==1) {
			cout << 1 << endl;
			continue;
		}
		
		vector<int> gcds(2, a[0]);		
		
		for(int i=0; i < n; i++) {
			if (i==n-1) {
				gcds[0] = __gcd(gcds[0], __gcd(a[i], i+1));
				gcds[1] = __gcd(gcds[1], a[i]);
				continue;
			}
			
			if (i == n-2) {
				gcds[1] = __gcd(gcds[1], __gcd(a[i], i+1));
				gcds[0] = __gcd(gcds[0], a[i]);
				continue;
			}
			
			gcds[0] = __gcd(gcds[0], a[i]);
			gcds[1] = __gcd(gcds[1], a[i]);
		}
		
		if (gcds[0] == 1) {
			cout << 1 << endl;
			continue;
		} 
		
		if (gcds[1] == 1) {
			cout << 2 << endl;
			continue;
		}
		
		cout << 3 << endl;
		continue;
	}
}