#include<bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin >> t;
	
	while(t--) {
		string s;
		cin >> s;
		
		
		bool can = (s[0] == 'B' || s.back() == 'B');
		
		vector<int> a;
		int cnt = 0;
		
		for(int i=0; i < s.size(); i++) {
			if (i+1 < s.size() && s[i] == 'B' && s[i+1] == 'B')
				can = true;
				
			if (s[i] == 'A')
				cnt++;
			else {
				a.push_back(cnt);
				cnt = 0;
			}
		}
		
		if (cnt)
			a.push_back(cnt);
		
		if (a.empty()) {
			cout << 0 << endl;
			continue;
		}
		
		sort(a.begin(), a.end());
		
		int ans = accumulate(a.begin(), a.end(), 0);
		
		if (!can)
			ans -= a[0];
			
		cout << ans << endl;
	}
}