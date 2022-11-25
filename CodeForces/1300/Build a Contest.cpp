#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin >> n >> m;
	
	map<int,int> mp;
	set<int> s, t;
	
	for(int i=0; i < m; i++) {
		int x;
		cin >> x;
		
		s.insert(x);
		mp[x]++;
		
		if (mp[x] == 1) {
			t.insert(x);
		} else {
			t.erase(x);
		}
		
		if (s.size() == n) {
			cout << 1;
			
			for(auto y : t) {
				s.erase(y);
				mp[y]--;
			}
			
			for(auto z : s) {
				mp[z]--;
				
				if (mp[z] == 1)
					t.insert(z);
			}
			
		} else {
			cout << 0;
		}
	}
}