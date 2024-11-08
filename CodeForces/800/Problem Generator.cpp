#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t=1;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		string s;
		cin >> s;
		
		vector<int> a(7, 0);
		for(auto &c : s)
			a[c - 'A']++;
		
		int cnt = 0;
		
		for(auto &ai : a)
			cnt += max(0, m - ai);
			
		cout << cnt << endl;
	}
}