#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
	
		map<pair<int,int>, int> m;
		
		if (n == 2) {
			int c;
			
			cout << "? 1 2" << endl;
			cin >> c;
			
			if (c == 0) {
				cout << "! IMPOSSIBLE" << endl;
				continue;
			}
			
			cout << "! 01" << endl;
			continue;
		}
		
		if (n == 3) {
			int c;
			
			cout << "? 1 2" << endl;
			cin >> c;
			
			m[{1, 2}] = c;
			
			cout << "? 2 3" << endl;
			cin >> c;
			
			m[{2, 3}] = c;
						
			cout << "? 1 3" << endl;
			cin >> c;
			
			m[{1, 3}] = c;
			
			if (m[{1, 3}] == 0) {
				cout << "! IMPOSSIBLE" << endl;
				continue;
			}
			
			// test all 8 possibilities
			for(int i=0; i < (1 << 3); i++) {
				string x = bitset<3>(i).to_string();
				map<pair<int,int>,int> M;
				
				M[{1, 2}] = (x[0] == '0' && x[1] == '1');
				M[{2, 3}] = (x[1] == '0' && x[2] == '1');
				M[{1, 3}] = M[{1, 2}] + M[{2, 3}] + (x[0] == '0' && x[2] == '1');
				
				bool can = true;
				
				for(auto [k, c] : M)
					can &= (m[k] == c);
		
				if (can) {
					cout << "! " << x << endl;
					break;
				}
			}
			
			continue;
		}
		
		for(int i=1; i < n; i++) {
			int c;
			
			cout << "? " << i << " " << n << endl;
			cin >> c;
			
			m[{i, n}] = c;
		}
		
		if (m[{1, n}] == 0) {
			cout << "! IMPOSSIBLE" << endl;
			continue;
		}
		
		// construct 
		string s = "";
		int x = -1;
		
		for(int i=2; i <= n; i++) {
			if (m[{i, n}] == 0) {
				s += '0';
				x = i-1;
				
				break;
			}
			
			if (m[{i, n}] == m[{i-1, n}])
				s += '1';
			else
				s += '0';
		}
		
		for(int i=0; i < m[{x, n}]; i++) {
			s += '1';
		}
		
		while(s.size() < n)
			s += '0';
		
				
		cout << "! " << s << endl;
	}
}