#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
	
		int n = s.size();
		
		int days = 1;
		set<char> w;
		
		for(int i=0; i < n; i++) {
			if (w.size() == 3 && !w.count(s[i])) {
				w.clear();
				
				days++;
			}
			
			w.insert(s[i]);
		}
		
		cout << days << endl;
	}
}