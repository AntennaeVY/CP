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

		bool ok = false;		
		int x = 0, y = 0;
		
		for(char c : s) {
			if (c == 'U') 
				y++;
			else if (c == 'L')
				x--;
			else if (c == 'R')
				x++;
			else
				y--;
				
			if (x == 1 && y == 1)
				ok = true;
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}