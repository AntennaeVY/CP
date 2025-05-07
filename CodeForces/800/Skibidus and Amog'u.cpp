#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		cout << s.substr(0, s.size() - 2) + "i" << endl;
	}
}