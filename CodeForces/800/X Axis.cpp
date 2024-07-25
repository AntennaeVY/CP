#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		
		int mn = 1e9;
		
		for(int i=1; i <= 10; i++) {
			mn = min(mn, abs(a - i) + abs(b - i) + abs(c - i));
		}
		
		cout << mn << endl;
	}
}