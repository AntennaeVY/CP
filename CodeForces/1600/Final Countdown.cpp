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
		
		vector<int> p(n+1);
		for(int i=0; i < n; i++) {
			p[i+1] = p[i] + s[i] - '0';
		}
		
		string ans = "";
		
		int carry = 0;
		for(int i=n; i >= 1; i--) {
			int sum = p[i] + carry;
			
			ans += char(sum % 10 + 48);
			
			carry = sum/10;
		}
		
		if (carry)
			ans += char(carry + 48);
		
		reverse(ans.begin(), ans.end());
		
		int i=0;
		while(ans[i] == '0') i++;
		
		for(; i < ans.size(); i++)
			cout << ans[i];
		
		cout << endl;
	}
}