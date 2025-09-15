#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m, x;
		cin >> n >> m >> x;
		
		set<int> s;
		s.insert(x-1);
		
		while(m--) {
			int r;
			char c;
			
			cin >> r >> c;
			set<int> s2;
			
			for(auto &si : s) {
				if (c == '0' || c == '?')
					s2.insert((si+r) % n);
				
				if (c == '1' || c == '?')
					s2.insert((si-r+n) % n);
			}
			
			s = s2;
		}
		
		cout << s.size() << "\n";
		for(auto &si : s)
			cout << si+1 << " ";
		cout << "\n";
	}
}