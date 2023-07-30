#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		sort(s.begin(), s.end());
		
		if (k == 1) {
			cout << s << endl;
			continue;
		}
		
		map<char, int> m;
		for(char c : s)
			m[c]++;
		
		string ans = "";
		ans += s[k-1];
		
		if (m[s[0]] < k) {
			cout << ans << endl;
			continue;
		}
		
		m[s[0]] -= k;
		
		if (k < n && s[k] == s[n-1]) {
			ans += string((m[s[k]]+k-1)/k, s[k]);
		} else if (k < n) {
			ans += s.substr(k);
		}
		
		cout << ans << endl;
	}
}