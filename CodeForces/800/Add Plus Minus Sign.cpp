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
		
		int sum = s[0] - 48;
		string ans = "";
		
		for(int i=1; i < n; i++) {
			if (sum - (s[i] - 48) < 0) {
				ans += "+";
				sum += s[i] - 48;
			} else {
				ans += "-";
				sum -= s[i] - 48;
			}
			
		}
		
		cout << ans << endl;
	}
}