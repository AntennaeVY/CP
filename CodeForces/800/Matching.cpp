#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		string s;
		cin >> s;

		int q = count(s.begin(), s.end(), '?');
	
		if (s[0] == '0') {
			cout << 0 << endl;
		} else if (s[0] == '?') 
			cout << 9 * pow(10, q-1) << endl;
		else 
			cout << pow(10, q) << endl;
	}
}