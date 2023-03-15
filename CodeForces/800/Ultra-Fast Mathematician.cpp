#include<bits/stdc++.h>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	
	for(int i=0; i < s.size(); i++) {
		t[i] = ((int)t[i] ^ (int)s[i]) + 48;
	}
	
	cout << t << endl;
}