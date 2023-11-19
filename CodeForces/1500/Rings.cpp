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
		
		int c1 = count(s.begin(), s.end(), '1');
		
		if (c1 == n) {
			cout << 1 << " " << n-1 << " ";
			cout << 2 << " " << n << endl;
			
			continue;
		}
		
		bool ok = false;
		
		for(int i=0; i < n/2; i++) {
			if (s[i] == '0') {
				cout << i+2 << " " << n << " ";
				cout << i+1 << " " << n << endl;
				
				ok = true;
				break;
			}
		}
		
		if (ok)
			continue;
		
		for(int i=n/2; i < n; i++) {
			if (s[i] == '0') {
				cout << 1 << " " << i+1 << " ";
				cout << 1 << " " << i << endl;
				
				break;
			}
		}
	}
}