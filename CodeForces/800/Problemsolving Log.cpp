#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		map<char, int> m;
		
		for(char c : s) {
			m[c]++;
		}
		
		int ans = 0;
		
		for(int i=1; i <= 26; i++) {
			if (m['A' + i - 1] >= i)
				ans += 1;
		}
		
		cout << ans << endl;
	}
}