#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		if (count(s.begin(), s.end(), s[0]) == 4) {
			cout << -1 << endl;
			continue;
		}
		
		if (count(s.begin(), s.end(), s[0]) == 3 || count(s.begin(), s.end(), s[1]) == 3) {
			cout << 6 << endl;
			continue;
		}
		
		cout << 4 << endl;
	}
}