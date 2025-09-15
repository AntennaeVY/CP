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
		
		char c = '9';
		for(auto &ch : s)
			c = min(c, ch);
			
		cout << c << endl;
	}
}