#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int n = s.size();
		
		bool can = false;
		
		for(int i=1; i < n; i++) {
			if (s[i] != s[0]) {
				can = true;
				swap(s[i], s[0]);
				break;
			}
		}
		
		if (can)
			cout << "YES\n" << s << endl;
		else
			cout << "NO" << endl; 
	}
}