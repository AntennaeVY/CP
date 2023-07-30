#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int q;
	cin >> q;
	
	while(q--) {
		int k;
		char c;
		cin >> k >> c;
		
		int cnt = 0, l = 0, ans = 0;
		
		for(int r=0; r < n; r++) {
			if (s[r] == c)
				cnt++;
				
			while(r-l+1 - cnt > k) {
				if (s[l] == c)
					cnt--;
					
				l++;
			}
			
			ans = max(ans, r-l+1);
		}
		
		cout << ans << endl;
	}
}