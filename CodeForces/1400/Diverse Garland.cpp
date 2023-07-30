#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	map<char, int> m = {{'R', 0}, {'G', 1}, {'B', 2}};
	string colors = "RGB";
	
	int ans = 0;
	
	for(int i=1; i < n-1; i++) {
		if (s[i] == s[i-1] && s[i] == s[i+1]) {  
			s[i] = colors[(m[s[i]] + 1) % 3];
			ans++;
		} else if (s[i] == s[i-1]) {
			if (colors[(m[s[i]] + 1) % 3] == s[i+1])
				s[i] = colors[(m[s[i]] + 2) % 3];
			else
				s[i] = colors[(m[s[i]] + 1) % 3];
			
			ans++;
		} 
	} 
	
	if (s[n-1] == s[n-2]) {
		s[n-1] = colors[(m[s[n-2]] + 1) % 3];
		ans++;
	}
	
	cout << ans << endl;
	cout << s << endl;
}