#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	
	int n = s.size();
	
	int m;
	cin >> m;
	
	int ans = 0;
	
	for(int i=0; i < 26; i++) {
		int del = 0;
		
		int l=0, r=n+1;
		while(l+1 < r) {
			int x = l + (r-l)/2;
			
			vector<int> cnt(26, 0);
			bool ok = false;
			int mn = 1e9;
			
			int L=0;
			for(int R=0; R < n; R++) {
				cnt[s[R] - 'a']++;
				
				while(R-L+1 > x)
					cnt[s[L] - 'a']--, L++;
					
				if (R-L+1 == x && R-L+1 - cnt[i] <= m) 
					ok = true, mn = min(mn, R-L+1 - cnt[i]);
			}
			
			if (ok)
				l = x, del = mn;
			else
				r = x;
		}
		
		ans = max(ans, l - del);
	}
	
	cout << ans << '\n';
}