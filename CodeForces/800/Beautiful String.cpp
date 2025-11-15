#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string s;
		cin >> s;
		
		if (count(s.begin(), s.end(), '0') == n) {
			cout << 0 << "\n\n";
			continue;
		}
		
		vector<int> ans;
		for(int i=0; i < n; i++)
			if (s[i] == '0')
				ans.push_back(i+1);
				
		cout << ans.size() << endl;
		for(auto &ansi : ans)
			cout << ansi << " ";
		cout << "\n";
	}
}