#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		s += "R";
		int prev = -1, ans = 0;
		
		for(int i=0; i < s.size(); i++) {
			if (s[i] == 'L')
				continue;
				
			ans = max(ans, i - prev);
			prev = i;
		}
		
		cout << ans << endl;
	}		
}