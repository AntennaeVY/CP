#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n), b(n+1, 1);
		for(auto &ai:a) cin >> ai;
		
		for(int i=0; i < n; i++) {
			b[i] *= a[i]/__gcd(a[i], b[i]);
			b[i+1] *= a[i]/__gcd(a[i], b[i+1]);
		}
		
		bool ok = true;
		
		for(int i=0; i < n; i++) {
			if (__gcd(b[i], b[i+1]) != a[i]) 
				ok = false;
		}
		
		cout << (ok ? "YES" : "NO") << endl; 
	}
}