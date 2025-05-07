#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while (t--) {
		string s;
		cin >> s;
		
		bool can = false;
		
		for(int i=1; i < s.size(); i++) {
			can |= s[i] == s[i-1];
		}
		
		cout << (can ? 1 : s.size()) << endl;
	}
}