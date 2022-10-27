#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai:a) cin >> ai;
		
		string s;
		cin >> s;
		
		vector<char> m(51, 0);
		bool ok = true;
		
		for(int i=0; i < n; i++) {
			if (m[a[i]] == 0)
				m[a[i]] = s[i];
			else if (m[a[i]] != s[i])
				ok = false;
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}