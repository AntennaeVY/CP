#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string n;
		cin >> n;
		
		if (n.size() < 3) {
			cout  << "NO" << endl;
			continue;
		}
		
		if (n[0] != '1' || n[1] != '0') {
			cout << "NO" << endl;
			continue;
		}
		
		string m = n.substr(2);
		
		if (m[0] == '0') {
			cout << "NO" << endl;
			continue;
		}
		
		if (stoi(m) < 2) {
			cout << "NO" << endl;
			continue;
		}
		
		cout << "YES" << endl;
	}
}