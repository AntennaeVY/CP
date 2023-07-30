#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n,k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		vector<int> ans(n, 0);
		int realk = k;
		bool odd = k%2;
		
		for(int i=0; i < n; i++) {
			if (odd && s[i] == '1' && k != 0) {
				ans[i]++;
				k--;
			}
			
			if (!odd & s[i] == '0' && k != 0) {
				ans[i]++;
				k--;
			}
		}
		
		ans[n-1] += k;
		
		for(int i=0; i < n; i++) {
			if ((realk-ans[i])%2 == 1) {
				s[i] = (s[i]^'1')+48;
			}
		}
		
		cout << s << endl;
		
		for(auto x : ans) {
			cout << x << " ";
		}
		
		cout << endl;
	}
}