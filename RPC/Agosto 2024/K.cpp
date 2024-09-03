#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	
	getline(cin, s);
	cin.ignore();
	
	int n = s.size();
	
	int ans = 0;
	bool shift = false;
	char last = '?';
	
	for(int i=0; i < n; i++) {
		if (!shift && isupper(s[i])) 
			ans += 1, shift = true;
		
		if (islower(s[i]))
			shift = false;
			
		if (tolower(s[i]) != tolower(last))
			ans += 1;
			
		last = s[i];
	}
	
	cout << ans << endl;
}