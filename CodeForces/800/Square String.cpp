#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		if (s.size()%2) {
			cout << "NO" << endl;
			continue;
		}
		
		bool good = true;
		
		for(int i=0; i < s.size()/2; i++) {
			if (s[i] != s[i+s.size()/2])
				good = false;
		}
		
		cout << (good ? "YES" : "NO") << endl;
	}
}