#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int a, b, c;
		
		cin >> a >> b >> c;
		
		if (c < (3 - b) % 3) {
			cout << -1 << endl;
			continue;
		}
		
		cout << a + (b+c+2)/3 << endl;
	}
}