#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		for(int i=0; i < n; i++) {
			int x; 
			cin >> x;
		}
		
		int qty = 10 - n;
		
		cout << 3*(qty)*(qty-1) << endl;
	}
}