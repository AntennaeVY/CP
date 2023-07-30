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
		
		if (n >= 3 || s == "00" || s == "11") {
			cout << "NO" << endl;
			continue;
		} 
		
		cout << "YES" << endl;
	}
}