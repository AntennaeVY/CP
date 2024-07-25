#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		for(int i=1; i <= n-2; i++) {
			cout << i << " " << i << endl;
		}
		
		cout << n-1 << " " << n << endl;
		cout << n << " " << n << endl << endl;
	}	
}