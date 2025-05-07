#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		string p;
		cin >> p;
		
		string s;
		cin >> s;
		
		int n = p.size();
		int m = s.size();
		
		p.push_back('*');
		s.push_back('*');
		
		bool ok = true;
		
		int l=0, L=0;
		while(l < n || L < m) {
			int x = 1, y = 1;
			
			while(l < n && p[l+1] == p[l])
				l++, x++;
				
			while(L < m && s[L+1] == s[L])
				L++, y++;
				
			if (s[L] != p[l] || y > 2*x || y < x) {
				ok = false;
				break;
			}
			
			l++, L++;
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}