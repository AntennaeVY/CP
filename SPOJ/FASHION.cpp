#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> m(n), f(n);
		for(auto &mi : m) cin >> mi;
		for(auto &fi : f) cin >> fi;
		
		sort(m.rbegin(), m.rend());
		sort(f.rbegin(), f.rend());
		
		int ans = 0;
		
		for(int i=0; i < n; i++) {
			ans += m[i] * f[i];
		}
		
		cout << ans << endl;
	}
}