#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int m = 0, b = 0;
		
		for(int i=0; i < n; i++) {
			int x;
			cin >> x;
			
			if (x % 2)
				b += x;
			else
				m += x;
		}
		
		cout << (m > b ? "YES" : "NO") << endl;
 	}
}