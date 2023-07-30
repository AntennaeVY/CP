#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int m, n = s.size();
		cin >> m;
		
		string l, r;
		cin >> l >> r;
		
		bool can = false;
		int last = 0;
		
		for(int i=0; i < m; i++) {
			int mx = last;
			
			for(int j=0; j <= r[i]-l[i]; j++) {
				bool found = false;
				
				for(int k=last; k < n; k++) {
					if (s[k] == l[i] + j) {
						mx = max(mx, k);
						found = true;
						break;
					}
				}
				
				if (!found)
					can = true;
			}
			
			last = mx+1;
		}
		
		cout << (can ? "YES" : "NO") << endl;
	}
}