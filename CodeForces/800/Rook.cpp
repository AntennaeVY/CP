#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		char x;
		int y;
		cin >> x >> y;
		
		for(int i=1; i <= 8; i++) {
			if (y != i)
				cout << x << i << endl;
		}
		
		for(int i=0; i < 8; i++) {
			if (x != 'a' + i)
				cout << char('a' + i) << y << endl;
		}
	}
}