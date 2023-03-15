#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int a, b;
		cin >> a >> b;
		
		int ans = b-a;
		
		// min (a + x) + (a + x) | (b + y)
		for(int a1=a; a1 < b; a1++) {
			int b1 = 0;
			
			for(int i=20; i >= 0; i--) {		
				b1 |= (1 << i) & ((1 << i) & a1 | (1 << i) & b);
				
				if (((a1 >> i) & 1) && !((b >> i) & 1)) 
					break;
			}
			
			ans = min(ans, (a1-a) + (b1-b) + (a1 | b1) - b1 + 1);
		}
		
		cout << ans << endl;
	}
}