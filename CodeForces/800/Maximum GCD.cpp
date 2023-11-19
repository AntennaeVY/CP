#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		int ans = 1;
		
		for(int i=1; i <= n; i++) {
			if (i*2 <= n)
				ans = i;
		}
		
		cout << ans << endl;
	}	
}