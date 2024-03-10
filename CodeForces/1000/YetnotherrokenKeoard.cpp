#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int n = s.size();
		
		stack<int> x, y;
		
		for(int i=0; i < n; i++) {
			if (s[i] == 'b' && !x.empty()) {
				x.pop();
			} else if (s[i] == 'B' && !y.empty()) {
				y.pop();
			}
			
			if (s[i] == 'b' || s[i] == 'B')
				continue;
				
			if (islower(s[i]))
				x.push(i);
			else
				y.push(i);
		}
		
		string ans = "";
		
		while(!x.empty() && !y.empty()) {
			if (x.top() > y.top()) {
				ans += s[x.top()];
				x.pop();
			} else {
				ans += s[y.top()];
				y.pop();
			}
		}
		
		while(!x.empty()) {
			ans += s[x.top()];
			x.pop();
		}
		
		while(!y.empty()) {
			ans += s[y.top()];
			y.pop();
		}
		
		reverse(ans.begin(), ans.end());
		
		cout << ans << "\n";
	}
}