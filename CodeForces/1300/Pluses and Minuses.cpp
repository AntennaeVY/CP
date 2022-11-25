#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int cnt = 0,mn = 0;
		long long ans = 0;
		
		for(int i=0; i < s.size(); i++) {
			if (s[i] == '-')
				cnt -= 1;
			else
				cnt += 1;
				
			if (cnt < mn) {
				mn = cnt;
				ans += i+1;
			}
		}
		
	 	ans += s.size();
	 	
	 	cout << ans << endl;
	}
}