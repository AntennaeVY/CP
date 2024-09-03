#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int a, b;
		cin >> a >> b;
		
		if (a % 2 || a == 0 && b % 2) {
			cout << "NO" << endl;
			continue;
		}
		
		cout << "YES" << endl;
	}
}