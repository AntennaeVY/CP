#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		string ans(n, 'a');
		
		for(int i=n-2; i >= 0; i--) {
			if (k == 0)
				break;
			
			for(int j=n-1; j > i; j--) {
				if (k-- == 1) {
					ans[i] = ans[j] = 'b';
					break;
				}	
			}	
		}
		
		cout << ans << endl;
	}
}