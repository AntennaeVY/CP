#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int ans = 0;
		
		if (s.size() == 1) {
			cout << 0 << endl;
			continue;
		}
		
		if (s[0] == s[1]) {
			ans++;
			s[1] = '$';
		}
		
		for(int i=2; i < s.size(); i++) {
			if (s[i] == s[i-1] || s[i] == s[i-2]) {
				ans++;
				s[i] = '$';
			}
		}
		
		cout << ans << endl;
	}
}