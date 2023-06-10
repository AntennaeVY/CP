#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		for(int i=0; i < s.size(); i++) {
			s[i] = tolower(s[i]);
		}
		
		if (s == "yes")
			cout << s << endl;
		else
			cout << "no" << endl;
	}
}