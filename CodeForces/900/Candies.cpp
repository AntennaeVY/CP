#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int ans = 0;
		
		for(int i=2; (1 << i) - 1 <= n; i++) {
			int k = (1 << i) - 1;
			
			if (n % k == 0) {
				cout << n/k << endl;
				break;
			}
		}
	}
}