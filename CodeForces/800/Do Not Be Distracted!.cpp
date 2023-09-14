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
		
		char last = '?';
		set<int> st;
		
		bool ok = true;
		
		for(int i=0; i < n; i++) {
			if (st.count(s[i]) && last != s[i])
				ok = false;
		
			st.insert(s[i]);
			last = s[i];
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}