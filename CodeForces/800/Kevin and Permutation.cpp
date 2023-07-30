#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		for(int i=0; i < n/2; i++) {
			cout << n/2 + i + 1 << " " << i + 1 << " ";
		}
		
		if (n%2)
			cout << n;
			
		cout << endl;
	}
}