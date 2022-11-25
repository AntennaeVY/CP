#include<bits/stdc++.h>
using namespace std;

int main() {
	string j, s;
	cin >> j >> s;
	
	map<char, bool> m;
	int ans = 0;
	
	for(char ch : j) {
		m[ch] = true;
	}
	
	for(char ch : s) {
		ans += m[ch];
	}
	
	cout << ans << endl;
}