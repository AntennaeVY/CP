#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int x;
		cin >> x;
		
		string s = "123456789";
		int ans = 1e9;
		
		
		do {
			int cnt = 0;
			for(int i=0; i < 9; i++) {
				cnt += s[i] - 48;
				
				if (cnt == x) {
					ans = min(ans, stoi(s.substr(0, i+1)));
				}
			} 
		} while(next_permutation(s.begin(), s.end()));
	
		if (ans != 1e9)
			cout << ans << endl;
		else
			cout << -1 << endl;
		
	}
}