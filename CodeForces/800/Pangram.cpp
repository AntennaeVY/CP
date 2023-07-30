#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	map<char, bool> m;
	for(auto &c : s) {
		m[tolower(c)] = true;
	}
	
	cout << (m.size() == 26 ? "YES" : "NO") << endl;
}