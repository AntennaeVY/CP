#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		bool ok = false;
		int a = 0, b = 0, c = 0;
		
		for(int i=2; i*i <= n; i++) {
			if (n%i)	
				continue;
				
			for(int j=i+1; j*j < n/i; j++) {
				if ((n/i) % j == 0) {
					ok = true;
					a = i, b = j, c = (n/i)/j;
					break;
				}
			}
			
			if (ok)
				break;
		}
		
		if (ok)
			cout << "YES\n" << a << " " << b << " " << c << endl;
		else
			cout << "NO" << endl;
	}
}	