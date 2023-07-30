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
		
		int i = 0, ans = 0;
		while(i < n && s[i] == '0') i++;
		
		for(int j=i; j < n; j++) {
			if (s[j] == '0' && ans%2 == 0 || s[j] == '1' && ans%2 == 1) {
				ans++;
			} 
		}
		
		cout << ans << endl;
	}
}