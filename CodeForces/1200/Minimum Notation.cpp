#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int n = s.size();
		
		string ans = "";
		vector<int> mn(n, 0);
		
		mn[n-1] = s.back() - '0';
		
		for(int i=n-2; i >= 0; i--) {
			mn[i] = min(s[i] - '0', mn[i+1]);
		}
		
		for(int i=0; i < n; i++) {
			if (s[i] - '0' > mn[i]) {
				ans += to_string(min(s[i]-'0'+1, 9));
			} else {
				ans += s[i];
			}
 		}
 		
 		sort(ans.begin(), ans.end());
 		
 		cout << ans << endl;
	}
}