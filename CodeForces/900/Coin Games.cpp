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
		
		bool first = true;
		
		while(n > 0) {
			int both = -1;
			int one = -1;
			int none = -1;
			
			for(int i=0; i < n; i++) {
				if (s[i] == 'D')
					continue;
					
				if (s[(i - 1 + n) % n] == 'U' && s[(i + 1) % n] == 'U')
					both = i;
				else if (s[(i - 1 + n) % n] == 'U' || s[(i + 1) % n] == 'U')
					one = i;
				else
					none = i;
			}
			
			int pos = none;
			
			if (both != -1)
				pos = both;
			else if (one != -1)
				pos = one;
			
			if (pos == -1)
				break;
				
			s[(pos + 1 + n) % n] ^= 'U'^'D';
			s[(pos - 1 + n) % n] ^= 'U'^'D';
			
			s = s.substr(0, pos) + s.substr(pos + 1);
			
			n--;
			first = !first;
		}
		
		cout << (first ? "NO" : "YES") << endl;
	}
}