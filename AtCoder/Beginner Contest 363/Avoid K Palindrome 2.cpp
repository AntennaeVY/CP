#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	string s;
	cin >> s;
	
	int ans = 0;
	
	sort(s.begin(), s.end());
	
	do {
		
		bool ok = true;
		
		for(int i=0; i < n-k+1; i++) {
			
			int l = i;
			int r = i+k-1;
			
			while(l < r && s[l] == s[r])
				l++, r--;
			
			ok &= l < r;
			
			if (!ok)
				break;
		}
		
		ans += ok;
		
	} while(next_permutation(s.begin(), s.end()));
	
	cout << ans << endl;
}