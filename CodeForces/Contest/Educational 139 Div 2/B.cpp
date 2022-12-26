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
		
		map<string, int> m;
		bool ans = false;
		
		for(int i=0; i < n; i++) {
			if (m[s.substr(i, 2)] != 0 && m[s.substr(i, 2)] != i)
				ans = true;
				
			if (m[s.substr(i, 2)] == 0)
				m[s.substr(i, 2)] = i+1;
		}
		
		cout << (ans ? "YES" : "NO") << endl;
	}
}