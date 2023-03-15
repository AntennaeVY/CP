#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<string> t(2*n-2);	
		set<string> s;
		
		for(int i=0; i < 2*n-2; i++) {
			cin >> t[i];	
			s.insert(t[i]);
		}
		
		bool ok = true;
		
		for(auto &x : t) {
			reverse(x.begin(), x.end());
			
			ok &= s.count(x);
		}
		
		if (n == 2 && t[0] != t[1])
			ok = false;
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}