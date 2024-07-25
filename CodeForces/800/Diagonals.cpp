#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		if (k == 0) {
			cout << 0 << endl;
			continue;
		}
		
		if (k <= n) {
			cout << 1 << endl;
			continue;
		}
		
		k -= n;
		
		int r = 1;
		
		for(int i=1; i < n; i++) {
			r++;
			
			if (k <= n-i) 
				break;
				
			k -= n-i, r++;
			
			if (k <= n-i)
				break;
			
			k -= n-i;
		}
	
		cout << r << endl;
	}
}