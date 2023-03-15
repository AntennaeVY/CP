#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		string s;
		cin >> s;
		
		map<char, pair<int, int>> m;
		for(char c : s) {
			if (isupper(c))
				m[tolower(c)].second++;
			else
				m[tolower(c)].first++;
		}
		
		int ans = 0;
		
		for(auto &[_, p]: m) {
			auto [l, u] = p;
			
			ans += min(l, u) + min(k, abs(l-u)/2);
			k -= min(k, abs(l-u)/2);
		}
		
		cout << ans << endl;
	}
}