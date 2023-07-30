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
		
		bool ok = true;
		int i=0;
		string match = "meow";
		
		for(char c : match) {
			ok &= (c == tolower(s[i]));
			
			while(tolower(s[i]) == c)
				i++;
		}
		
		cout << (i == n && ok ? "YES" : "NO") << endl;
	}
}