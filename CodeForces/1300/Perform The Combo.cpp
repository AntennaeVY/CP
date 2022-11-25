#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		string s;
		cin >> s;
		
		vector<int> p(m), a(n, 0), cnt(26, 0);
		for(auto &pi:p) cin >> pi;
		
		for(int i=0; i < m; i++) {
			a[0] += 1;
			a[p[i]] -= 1;
		}
		
		a[0] += 1;
		
		for(int i=1; i < n; i++) {
			a[i] += a[i-1];
		}
		
		for(int i=0; i < n; i++) {
			cnt[s[i] - 'a'] += a[i];
		}
		
		for(auto it : cnt) {
			cout << it << " ";
		}
		
		cout << endl;
	}
}