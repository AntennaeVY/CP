#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int x, y, k;
		cin >> x >> y >> k;
		
		while(k) {
			int r = y - (x % y); 
			
			if (k < r)
				break;
			
			x += r, k -= r;
		
			while(x % y == 0)
				x /= y;	
				
			if (x == 1)
				break;
		}
		
		if (k >= y - (x % y))
			k %= (y-1);
		
		cout << x + k << endl;
	}
}