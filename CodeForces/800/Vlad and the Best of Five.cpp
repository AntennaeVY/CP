#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int a = count(s.begin(), s.end(), 'A');
		int b = 5 - a;
		
		cout << (a > b ? 'A' : 'B') << endl;
	}
}