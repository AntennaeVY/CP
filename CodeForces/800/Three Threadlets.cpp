#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int a, b, c;
		cin >> a >> b >> c;
		
		if (b < a)
			swap(a, b);
		
		if (c < a)
			swap(a, c);
		
		if (b % a != 0 || c % a != 0) {
			cout << "NO" << endl;
			continue;
		}
		
		if (b/a + c/a - 2 <= 3) {
			cout << "YES" << endl;
			continue;
		}
		
		cout << "NO" << endl;
	}
}