#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	bool ok = true;
	
	for(int i=1; i < s.size(); i++) {
	    char c = s[i];
		ok &= (c != tolower(c));
	}
	
	if (!ok) {
		cout << s << endl;
		return 0;
	}
	
	for(int i=1; i < s.size(); i++) {
		s[i] = tolower(s[i]);
	}
	
	s[0] = s[0]^toupper(s[0])^tolower(s[0]);
	
	cout << s << endl;
}