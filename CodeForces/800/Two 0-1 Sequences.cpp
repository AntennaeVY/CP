#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		string a,b;
		cin >> a >> b;
		
		bool ok = true;
		
		for(int i=1; i < m; i++) {
			ok &= a[i+(n-m)] == b[i];
		}
		
		bool can = false;
		
		for(int i=0; i <= n-m; i++) {
			can |= a[i] == b[0];
		}
		
		cout << (ok & can ? "YES" : "NO") << endl;
	}
}