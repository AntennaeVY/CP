#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		char c;
		cin >> c;
		
		string s = "codeforces";
		
		cout << (count(s.begin(), s.end(), c) ? "YES" : "NO") << endl;
	}
}