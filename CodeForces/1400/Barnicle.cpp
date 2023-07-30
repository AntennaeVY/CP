#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int e = -1, dot = -1;
	
	for(int i=0; i < s.size(); i++) {
		if (s[i] == 'e')
			e = i;
		
		if (s[i] == '.')
			dot = i;
	}
	
	int b = stoi(s.substr(e+1));
	
	if (b == 0 && dot != -1 && s.substr(dot+1, e-(dot+1)) == "0") {
		cout << s.substr(0, dot);
		return 0;
	}
	
	
	if (b == 0) {
		cout << s.substr(0, e);
		return 0;
	}
	
	if (s[0] != '0')
		cout << s[0];
		
	if (dot == -1) {
		cout << s.substr(1, e-1) + string(b, '0');
		return 0;
	}
	
	if (b < e-dot-1) {
		cout << s.substr(dot+1, b) + "." + s.substr(dot+1+b, e-(dot+1+b));
		return 0;
	}
	
	cout << s.substr(dot+1, e-dot-1);
	
	if (b > e-dot-1) 
		cout << string(b - (e-dot-1), '0');

}