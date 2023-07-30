#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	if (s == "0") {
		cout << "NO" << endl;
		return 0;
	}
	
	bool ok = true;
	
	if (s[0] == '0' && s[1] == '0' || s[n-1] == '0' && s[n-2] == '0') {
		ok = false;
	}
	
	for(int i=1; i < n; i++) {
		if (s[i] == '1' && s[i-1] == '1')
			ok = false;
			
		if (i+2 < n && s[i] == '0' && s[i+1] == '0' && s[i+2] == '0') {
			ok = false;
		}
	}
	
	cout << (ok ? "YES" : "NO") << endl;
}