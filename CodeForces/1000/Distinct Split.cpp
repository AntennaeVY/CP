#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		set<char> st(s.begin(), s.end());
		
		int cnt_a = 0, cnt_b = st.size();
		map<char, int> a, b;
		
		for(char c : s) {
			b[c]++;
		}
		
		int ans = 0;
		for(int i=0; i < n; i++) {
			if (a[s[i]] == 0)
				cnt_a++;
			
			if (b[s[i]] == 1)
				cnt_b--;
				
			a[s[i]]++;
			b[s[i]]--;			
			
			ans = max(ans, cnt_a + cnt_b);
		}
		
		cout << ans << endl;
	}
}