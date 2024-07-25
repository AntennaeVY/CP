#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int x, y, z;
		long long k;
		
		cin >> x >> y >> z >> k;
		
		long long ans = 0;
		
		for(long long i=1; i <= x; i++) {
			if (k % i)
				continue;
			
			for(long long j=1; j <= y; j++) {
				if ((k/i) % j)
					continue;
					
				if (k/(i*j) > z)
					continue;
				
				ans = max(ans, (x - i + 1) * (y - j + 1) * (z - k / (i*j) + 1));
			}
		}
		
		cout << ans << endl;
	}
}