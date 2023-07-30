#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string abc;
		cin >> abc;
		
		map<char, int> m;
		for(int i=0; i < 26; i++) {
			m[abc[i]] = i;
		}
		
		string s;
		cin >> s;
		
		int n=s.size(), ans = 0;
		
		for(int i=1; i < n; i++) {
			ans += abs(m[s[i]] - m[s[i-1]]);
		}
		
		cout << ans << endl;
	}
}