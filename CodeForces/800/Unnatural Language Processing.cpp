#include<bits/stdc++.h>
using namespace std;

bool isCons(char x) {
	return x != 'a' && x != 'e';
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		string ans = "";
		
		ans += s[0];
		
		for(int i=1; i < n-1; i++) {
			if (isCons(s[i-1]) || !isCons(s[i])) {
				ans += s[i];
				continue;
			}
			
			// VCC
			if (isCons(s[i+1]))
				ans += s[i] + string(1, '.');
			
			// VCV
			if (!isCons(s[i+1]))
				ans += string(1, '.') + s[i];
		}
		
		ans += s.back();
		
		cout << ans << endl;
	}
}