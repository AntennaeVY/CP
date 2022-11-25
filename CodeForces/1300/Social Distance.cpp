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
		
		
		if (count(s.begin(), s.end(), '0') == n) {
			cout << (n + k)/(k+1) << endl;
			continue;
		}
		
		int ans = 0;
		int i=0, block = k;
		
		while(i < n && s[i] == '0') {
			block++;
			i++;
		}
		
		ans += max(block-k, 0)/(k+1);
		
		for(; i < n; i++) {
			block = 0;
			
			while(i < n && s[i] == '0') {
				block++;
				i++;
			}
			
			if (i < n)
				ans += max(block-k, 0)/(k+1);
			else
				ans += block/(k+1);
		}
		
		cout << ans << endl;
	}
}