#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s, t;
	
	getline(cin, s);
	cin.ignore();
	
	getline(cin, t);
	cin.ignore();
	
	set<char> st;
	
	for(auto c : t)
		st.insert(c);
		
	string ans = "";
	bool ch = false;
	
	
	for(int i=0; i < s.size(); i++) {
		if (!st.count(s[i]) && (ans.size() == 0 || ans[ans.size()-1] != s[i])) {
			if (s[i] != ' ')
				ch = true;
				
			if (ch)	
				ans += s[i];
		}
	}
	
	while(ans[ans.size() - 1] == ' ')
		ans.pop_back();
	
	cout << ans << endl;
}