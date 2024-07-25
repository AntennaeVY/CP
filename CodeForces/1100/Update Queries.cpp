#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		string s;
		cin >> s;
		
		vector<int> a(m);
		for(auto &ai : a) cin >> ai;
		
		string c;
		cin >> c;
		
		sort(a.begin(), a.end());
		a.erase(unique(a.begin(), a.end()), a.end());
		
		sort(c.begin(), c.end());
		
		for(int i=0; i < a.size(); i++) {
			s[a[i] - 1] = c[i];
		}
		
		cout << s << endl;
	}
}