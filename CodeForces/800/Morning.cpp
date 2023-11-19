#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int start = 1, ans = 0;
		
		for(int i=0; i < 4; i++) {
			int n = s[i] - 48;
			
			if (n == 0)
				n = 10;
				
			ans += abs(n - start) + 1;
			start = n;
		}
		
	    cout << ans << endl;
	}
	
}