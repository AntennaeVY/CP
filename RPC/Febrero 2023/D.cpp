#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		long long m;
		cin >> m;
		
		map<int, bool> can;
		set<long long> s;
		
		for(long long i=1; i*i <= m; i++) {
			if (m % i != 0)
				continue;
				
			s.insert(i), s.insert(m/i);
			can[i] = can[m/i] = true;
		}
		
		bool ans = true;
		
		for(long long i=1; i < m; i++) {
			bool ok = false;
			
			for(auto j : s) {
				if (abs(i-j) != j && can[abs(i-j)]) {
					can[i] = ok = true;
					break;
				}
			}
			
			if (!ok) {
				ans = false;
				break;
			}
		}
		
		if (m == 1)
			ans = false;
		
		cout << (ans ? "Yes" : "No") << endl;
	}
}