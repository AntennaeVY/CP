#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int i;
		bool ok = true;
		string match = "Yes";
	
		switch(s[0]) {
			case 'Y':
				i=0; break;
			case 'e':
				i=1; break;
			case 's':
				i=2; break;
			default:
				ok = false;
		}
			
		if (!ok) {
			cout << "NO" << endl;
			continue;
		}
		
		for(int j=0; j < s.size(); j++, i=(i+1)%3) {
			if (s[j] != match[i])
				ok = false;
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}