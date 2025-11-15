#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	
	map<char, int> m;
	
	for(char c : s)
		m[c]++;
		
	for(auto &[ch, c] : m) {
		if (c == 1) {
			cout << ch << "\n";
		}
	}
}