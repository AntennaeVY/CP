#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int o = 0, f = 0;
	
	for(int i=0; i < s.size(); i++) {
		o += s[i] == '1';
		f += s[i] == '4';
	}
	
	bool ok = true;
	
	if (o + f < s.size())
		ok = false;
	
	if (s[0] == '4')
		ok = false;
		
	if (s.find("444") != string::npos)
		ok = false;
		
	cout << (ok ? "YES" : "NO") << endl;
}