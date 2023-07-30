#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		if (n <= 2) {
			for(int i=1; i <= n; i++)
				cout << i << " ";
		} else {
			cout << 2 << " ";
			for(int i=0; i < n/2 - 1; i++)
				cout << 4 + i << " ";
			cout << 1 << " ";
			for(int i=n/2+2; i < n; i++)
				cout << 1 + i << " ";
			cout << 3 << " ";
		}
		
		cout << endl;
	}
}