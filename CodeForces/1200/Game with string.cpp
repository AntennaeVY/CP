#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	bool operation = false;
	int last = 1, cnt = 0;
	
	do {
		operation = false;
		
		for(int i=last; i < s.size(); i++) {
			if (s[i] == s[i-1]) {
				s.erase(i-1, 2);
				last = i-1;
				cnt++;
				operation = true;
				break;
			}
		}
	} while(operation);
	
	cout << ((cnt%2) ? "Yes" : "No") << endl;
 }