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
		
		string ans = "";
		char curr = '*';
		
		for(int i=0; i < n; i++) {
			if (curr == '*')
				ans += s[i], curr = s[i];
			else if (s[i] != curr)
				continue;
			else 
				curr = '*';
		}
		
		cout << ans << endl;
	}
}