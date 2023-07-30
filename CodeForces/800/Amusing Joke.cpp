#include<bits/stdc++.h>
using namespace std;

int main() {
	string guest, host, s;
	cin >> guest >> host >> s;
	
	map<char, int> m1, m2;
	for(char c : guest) m1[c]++;
	for(char c : host) m1[c]++;
	for(char c : s) m2[c]++;
	
	bool ok = true;
	
	for(auto &[c, i] : m1) {
		if (m2[c] != i)
		 	ok = false;
	}
	
	if (m2.size() > m1.size())
		ok = false;
	
	cout << (ok ? "YES" : "NO") << endl;
}