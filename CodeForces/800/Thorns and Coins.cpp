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
		
		s.push_back('*');
		s.push_back('*');
		
		int ans = 0;
		int i = 0;
		
		while(true) {
			if (s[i] == '@')
				ans++;
				
			if (s[i+1] == '*' && s[i+2] == '*')
				break;
				
			if (s[i+1] == '*')
				i++;
				
			i++;
		}
		
		cout << ans << endl;
	}
}