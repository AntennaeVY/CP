#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		cin.ignore();
		
		map<string, int> m;
		
		for(int i=0; i < n; i++) {
			string s;
			getline(cin, s, '\n');
			
			m[s] += 1;
		}
		
		for(auto [s, c] : m)
			cout << s << " " << c << endl;
		
		cout << endl;
	}

}