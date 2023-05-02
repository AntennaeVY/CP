#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int q;
	cin >> q;
	
	while(q--) {
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		int ans = 1e9;
		
		char chars[3] = {'R', 'G', 'B'};
		
		for(int i=0; i < 3; i++) {
			int cnt = 0, l = 0;
			
			for(int r=0; r < n; r++) {
				cnt += s[r] != chars[(r+i)%3];
				
				if (r-l+1 > k) {
					cnt -= s[l] != chars[(l+i)%3];
					l++;
				} 
				
				if (r-l+1 == k)
					ans = min(ans, cnt);
			}
		}
		
		cout << ans << endl;
	}
}