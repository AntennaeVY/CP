#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		if (k == 3 && n == 4) {
			cout << -1 << endl;
			continue;
		}
		
		if (k == n-1) {
			cout << n-1 << " " << n-2 << endl;
			cout << 1 << " " << n-3 << endl;
			cout << 0 << " " << 2 << endl;
			
			for(int i=3; i < n/2; i++) {
				cout << i << " " << (~i & (n-1)) << endl;
			}
			
			continue;
		} 
		
		if (k != 0)
			cout << 0 << " " << (~k & (n-1)) << endl;
			
		cout << k << " " << n-1 << endl;
		
		for(int i=1; i < n/2; i++) {
			if (i == k || (~i & (n-1)) == k)
				continue;
				
			cout << i << " " << (~i & (n-1)) << endl;			
		}
	}
}