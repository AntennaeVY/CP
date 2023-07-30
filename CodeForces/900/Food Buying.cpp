#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int ans = 0;
		
		while (n >= 10) {
			ans += 10*(n/10);
			n = n%10 + (n/10);
		}
		
		ans += n;
		
		cout << ans << endl;
	}
}