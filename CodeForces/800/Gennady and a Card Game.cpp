#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	vector<string> a(5);
	for(auto &ai : a) cin >> ai;
	
	bool ok = false;
	
	for(int i=0; i < 5; i++) {
		ok |= a[i][0] == s[0];
		ok |= a[i][1] == s[1];
	}
	
	cout << (ok ? "YES" : "NO") << endl;
}