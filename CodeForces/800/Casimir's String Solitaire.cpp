#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		map<char, int> m;
		
		for(auto c : s)
			m[c]++;
			
		if (m['A'] + m['C'] == m['B'])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}