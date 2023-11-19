#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int one = count(s.begin(), s.end(), '1');
		
		int cnt = one, ans = 0;
		
		for(int i=0; i < s.size(); i++) {
			if (s[i] == '0' && cnt > 0 && cnt < one)
				ans++;
			
			if (s[i] == '1')
				cnt--;
		}
		
		cout << ans <<  endl;
	}
}