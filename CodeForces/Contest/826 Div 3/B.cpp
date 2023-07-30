#include<bits/stdc++.h>
using namespace std;

int main() {
	int t = 1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		if (n == 3) {
			cout << -1 << endl;
			continue;
		}
		
		for(int i=n; i > 0; i--) {
			if (n%2 && i <= (n+1)/2)
				break;
				
			cout << i << " ";
		}
		
		for(int i=1; n%2 && i <= (n+1)/2; i++) {
			cout << i << " ";
		}
	
		cout << endl;
	}
}