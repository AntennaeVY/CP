#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
	
		string s;
		cin >> s;

		map<char, bool> seen;

		for(int i=0; i < n; i+=2) {
			seen[s[i]] = true;
		}
		
		bool ok = true;
		
		for(int i=1; i < n; i+=2) {
			if (seen[s[i]])
				ok = false;
		}
		
		cout << (ok ? "YES" : "NO") << endl;
 	}
}