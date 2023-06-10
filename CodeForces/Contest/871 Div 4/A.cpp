#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		string test = "codeforces";
		string s;
		cin >> s;
		
		int ans = 0;
		
		for(int i=0; i < test.size(); i++) {
			ans += s[i] != test[i];
		}
					
		cout << ans << endl;
	}
}