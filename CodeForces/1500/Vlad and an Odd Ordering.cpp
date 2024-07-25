#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
	
		/*
			n = 11
			
			1,3,5,7,9,11,2,6,10,4,8
			
			
			n = 13
			
			1,3,5,7,9,11,13,2,6,10,4,12
			
		*/
		
		// x * (2y - 1) <= n
		// 2y - 1 <= n / x;
		// 2y <= n / x + 1
		// y  <= floor((n / x + 1) / 2);

		
		int x = 1;
		while(true) {
			int y = (double(n)/x + 1) / 2;
			
			if (k > y) {
				k -= y;
				x *= 2;
				continue;
			}
			
			cout << x * (2*k - 1) << endl;
			break;
		}
	}
}