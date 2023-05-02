#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		char d;
		cin >> n >> d;
		
		string s;
		cin >> s;
		
		int idx = -1;
		
		for(int i=0; i < n; i++) {
			if (s[i] >= d)
				continue;

			idx = i;				
			break;
		}
		
		if (idx != -1)
			cout << s.substr(0, idx) + d + s.substr(idx) << endl;
		else
			cout << s + d << endl;
	}
	
	
}