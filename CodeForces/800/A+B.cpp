#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int plus_pos = s.find('+');

		cout << plus_pos << endl;		
		
		int a = stoi(s.substr(0, plus_pos));
		int b = stoi(s.substr(plus_pos+1));
		
		cout << a + b << endl;
	}
}