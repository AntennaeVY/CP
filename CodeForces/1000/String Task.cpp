#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	map<char, bool> vowels;
	
	vowels['A'] = vowels['a'] = true;
	vowels['E'] = vowels['e'] = true;
	vowels['I'] = vowels['i'] = true;
	vowels['O'] = vowels['o'] = true;
	vowels['U'] = vowels['u'] = true;
	vowels['Y'] = vowels['y'] = true;
	
	string ans = "";
	
	for(int i=0; i < s.size(); i++) {
		if (vowels[s[i]])
			continue;
			
		ans += "." + string(1, tolower(s[i]));
	}
	
	cout << ans << endl;
}