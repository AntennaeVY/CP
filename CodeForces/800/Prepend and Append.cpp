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
		
		int l=0, r=s.size()-1;
		int ans = 1;
		
		while(s[l] != s[r] && l < r) {
			l++, r--;
		}
		
		ans = max(0, r-l+1);
		
		cout << ans << endl;
	}
}