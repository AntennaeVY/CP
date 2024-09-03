#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<string> s(n);
		for(int i=0; i < n; i++) {
			cin >> s[i];
		}
		
		vector<string> ans;
		
		for(int i=0; i < n; i += k) {
			string p = "";
			
			for(int j=0; j < n; j += k) {
				p += s[i][j];
			}
			
			ans.push_back(p);
		}
		
		for(auto &ansi : ans)
			cout << ansi << endl;
	}
}