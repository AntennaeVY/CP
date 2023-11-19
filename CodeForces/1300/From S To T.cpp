#include<bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	
	while(q--) {
		string s, t, p;
		cin >> s >> t >> p;
		
		map<char, int> m;
		for(auto c : t)
			m[c]++;
			
		int n = s.size(), j = 0;
		
		for(int i=0; i < t.size() && j < n; i++) {
			if (t[i] == s[j])
				m[t[i]]--, j++;
		}
		
		if (j != n) {
			cout << "NO" << endl;
			continue;
		}
		
		for(int i=0; i < p.size(); i++) {
			m[p[i]]--;
		}
		
		bool ok = true;
		
		for(auto &[x, y] : m) {
			if (y > 0)
				ok = false;
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}