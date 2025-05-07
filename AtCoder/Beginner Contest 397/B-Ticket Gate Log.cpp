#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	
	int ans = 0;
	
	for(int i=0; i < s.size(); i++) {
		char match = (i % 2 == 0 ? 'i' : 'o');
		
		if (s[i] != match) {
			s = s.substr(0, i) + match + s.substr(i);
			ans++;
		}
	}
	
	if (s.size() % 2)
		ans++;

	cout << ans << endl;
}