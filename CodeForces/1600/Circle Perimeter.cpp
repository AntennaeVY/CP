#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long r;
		cin >> r;
		
		long long ans = 0, Y = r;
		
		for(long long x=0; x <= r; x++) {
			
			while(x*x + Y*Y >= (r+1)*(r+1))
				Y--;
			
			long long y = Y;
			
			while(y > 0 && x*x + y*y >= r*r)
				y--, ans++;
		}
		
		cout << ans * 4 << endl;
	}
}