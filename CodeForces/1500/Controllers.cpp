#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	long long pos = 0, neg = 0;
	for(char c : s)
		pos += (c == '+'), neg += (c == '-');
	
	int q;
	cin >> q;
	
	while(q--) {
		long long a, b;
		cin >> a >> b;
		
		if (pos == neg) {
			cout << "YES" << endl;
			continue;
		}
		
		if (a-b == 0) {
			cout << "NO" << endl;
			continue;
		}
		
		if ((pos-neg)*a % (a-b) != 0 || (pos-neg)*a / (a-b) > pos || (pos-neg)*a / (a-b) < -neg) {
			cout << "NO" << endl;
			continue;
		} 
		
		cout << "YES" << endl;
	}
}