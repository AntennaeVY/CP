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
		
		int ans = 0;
		stack<int> stk;
		
		for(int i=0; i < n; i++) {
			if (s[i] == ')' && stk.empty())
				ans++;
			else if (s[i] == ')')
				stk.pop();
			else
				stk.push(i);
		}
		
		cout << ans << endl;
	}
}