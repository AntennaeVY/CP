#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int x;
		cin >> x;
		
		long long p = x, y = 1;
		int cnt = 0;
		
		while(cnt < 2) {
			if (p == 1) {
				p++;
				continue;
			}
			
			if (p % 2 == 0 && p != 2) {
				p++;
				continue;
			}
			
			bool ok = true;
			
			for(long long i=3; i*i <= p; i+=2) {
				ok &= !(p % i == 0);
				
				if (!ok)
					break;
			}
			
			if (ok)
				y *= p, cnt++;
			
			if (p == 2)
				p++;
			else
				p += 2;
		}
		
		cout << y << endl;
	}
}