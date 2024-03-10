#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		bool can = false;
		
		for(int i=0; i < s.size(); i++) {
			can |= ((s[i] - '0') % 2 == 0);
		}
		
		if (!can)
			cout << -1 << endl;
		else
			cout << ((s.back() - '0') % 2 == 0 ? 0 : (s[0] - '0') % 2 + 1) << endl;
	}
}