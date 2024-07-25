#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	for(int _=1; _ <= t; _++){
		int n, r;
		cin >> n >> r;
		
		cout << "Scenario #" << _ << ": ";
		
		bool ok = true;
		map<int, set<int>> m;
		
		for(int i=0; i < r; i++) {
			int id, c;
			cin >> id >> c;
			
			if (m[id].count(c))
				ok = false;
				
			m[id].insert(c);
		}
		
		cout << (ok ? "possible" : "impossible") << endl;
	}
}