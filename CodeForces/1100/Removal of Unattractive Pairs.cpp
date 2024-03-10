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
		
		map<char, int> m;
		int mx = 0;
		
		for(char c : s)
			++m[c], mx = max(mx, m[c]);
			
		
		cout << max(n % 2, 2 * mx - n) << "\n";
	}
}