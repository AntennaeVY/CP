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
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int ans = 0;
		
		map<int, int> m;
		for(auto &ai : a) 
			++m[ai];

		for(auto [ai, c] : m)
			ans += (c / 2);
			
		cout << ans << endl;
	}
}