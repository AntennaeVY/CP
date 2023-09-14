#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		s = '0' + s;
		
		int n = s.size();
		int carry = 0, last = n;
		
		for(int i=n-1; i > 0; i--) {
			int d = s[i] - 48;
			
			if (d + carry == 10) {
				s[i] = '0';
				carry = 1;
				continue;
			}
			
			if (d + carry >= 5) {
				last = i;
				carry = 1;
				continue;
			}
			
			s[i] = char(d + carry + 48);
			carry = 0;
		}
		
		if (carry)
			s[0] = s[0] + 1;
			
		s = s.substr(0, last) + string(n - last, '0');
			
		if (s[0] == '0')
			s = s.substr(1);
	
		cout << s << endl;
	}
}