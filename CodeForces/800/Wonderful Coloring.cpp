#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		int ans = 0, one_cnt = 0;
		map<char, int> m;
		
		for(char c : s) {
			m[c]++;
		}
		
		for(auto it = m.begin(); it != m.end(); it++) {
			if (it->second == 1)
				one_cnt++;
		    else
		    	ans += 1;
		}
		
		cout << ans + one_cnt/2 << endl;
	}
}