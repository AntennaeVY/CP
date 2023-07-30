#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	int mx = 0, last = 0;
	for(int i=1; i < s.size(); i++) {
		if (s[i] == '0')
			continue;
			
		mx = max(mx, (i-last)/2);
		last = i; 
	}
	
	cout << mx << endl;
}