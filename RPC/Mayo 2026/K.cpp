#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	int ans = 0;
	int mx = 0;
	
	while(n--) {
		string s;
		cin >> s;
		
		if (s[0] == '/') {
			cout << ans << "\n";
			continue;
		}
		
		int x = stoi(s);
		mx = max(mx, x);
		
		ans = max(ans, (mx+10)/10 * 10);
		
		cout << x << "\n";
	}
}