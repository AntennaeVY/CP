#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int m;
		cin >> m;
		
		while(m--) {
			string s;
			cin >> s;
			
			if (s.size() != n) {
				cout << "NO" << endl;
				continue;
			}
			
			map<char, bool> seen;
			map<int, set<char>> mp;
			
			for(int i=0; i < n; i++) {
				mp[a[i]].insert(s[i]);
			}
			
			bool can = true;
			
			for(auto &[c, st] : mp) {
				can &= st.size() == 1;
				can &= seen[*st.begin()] == false;
				
				seen[*st.begin()] = true;
			}
			
			cout << (can ? "YES" : "NO") << endl;
		}
	}
}