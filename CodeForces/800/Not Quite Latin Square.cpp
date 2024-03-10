#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		for(int i=0; i < 3; i++) {
			string s;
			cin >> s;
			
			if (count(s.begin(), s.end(), '?') == 0)
				continue;
				
			int a = count(s.begin(), s.end(), 'A');
			int b = count(s.begin(), s.end(), 'B');
			int c = count(s.begin(), s.end(), 'C');
			
			if (b && c)
				cout << 'A' << endl;
			else if (a && c)
				cout << 'B' << endl;
			else 
				cout << 'C' << endl;
		}
	}
}