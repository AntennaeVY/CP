#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int ans = 0;
		stack<int> p;
		
		for(int i{}; i < s.size(); i++) {
			if (p.empty()) {
				p.push(s[i]);
				continue;
			}
			
			if (s[i] == 'B')
				p.pop();
			else
				p.push(s[i]);
		}
		
		cout << p.size() << endl;
 	}
}