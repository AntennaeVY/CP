#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		string match = "abc";
		bool ok = false;
		
		for(int i=0; i < 3; i++) {
			ok |= match[i] == s[i];
		}
		
		cout << (ok ? "YES" : "NO") << endl; 
	}
}