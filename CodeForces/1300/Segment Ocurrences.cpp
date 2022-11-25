#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,m,q;
	cin >> n >> m >> q;
	
	string s, t;
	cin >> s >> t;
	
	vector<int> ending(n+1, 0), starting(n+1, 0);
	
	for(int i=0; i <= n-m; i++) {		
		if (s[i] != t[0]) continue;
		
		if (s.substr(i, m) == t) {
			ending[i+m] += 1;
			starting[i+1] += 1;
		}
	}
	
	
	for(int i=1; i < n+1; i++) {
		ending[i] = ending[i-1] + ending[i];
		starting[i] = starting[i-1] + starting[i];
	}
	
	for(int i=0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		
		if (m > n) {
			cout << 0 << endl;
			continue;
		}
		
		if (r-l+1 >= m)
			cout << ending[r] - starting[l-1] << endl;
		else
			cout << 0 << endl;
	}
}