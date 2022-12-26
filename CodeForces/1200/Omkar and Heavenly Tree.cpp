#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<array<int, 3>> r(m);
		set<int> s;
		
		for(auto &ri:r) {
			for(auto &rj:ri) cin >> rj;
			
			s.insert(ri[1]);
		}
		
		int root = 0;
		
		for(int i=1; i <= n; i++) {
			if (s.count(i) == 0) {
				root = i;
				break;
			}
		}
		
		for(int i=1; i <= n; i++) {
			if (i != root)
				cout << root << " " << i << endl;
		}
	}
}