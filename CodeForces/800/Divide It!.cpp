#include<bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	
	while(q--) {
		long long n;
		cin >> n;
		
		int ans = 0;
		
		while(n % 5 == 0) {
			n /= 5;
			n *= 4;
			
			ans++;
		}
		
		while(n % 3 == 0) {
			n /= 3;
			n *= 2;
			
			ans++;
		}
		
		while(n % 2 == 0) {
			n /= 2;
			
			ans++;
		}
		
		if (n != 1) {
			cout << "-1" << endl;
		} else {
			cout << ans << endl;
		}
	}
}