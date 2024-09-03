#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		int c = 0, i = 0;
		while(s[i] == '1') {
			c++, i++;
		}
		
		if (n == 4) {
			cout << "Yes" << endl;
			continue;
		}
		
		c -= 1;
	
		
		if (n == c * c)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
}