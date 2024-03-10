#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	map<string, int> m;
	
	for(int i=0; i < n-1; i++) {
		m[s.substr(i, 2)]++;
	}
	
	int mx = 0; 
	string ans = "";
	
	for(auto [str, c] : m) {
		if (c > mx)
			ans = str, mx = c;
	}
	
	cout << ans << "\n";
}