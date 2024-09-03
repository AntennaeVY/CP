#include<bits/stdc++.h>
using namespace std;

map<string, string> cant = {
	{"BG", "RY"},
	{"BR", "GY"},
	{"BY", "GR"},
	{"GR", "BY"},
	{"GY", "BR"},
	{"RY", "BG"},
};

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, q;
		cin >> n >> q;
		
		vector<string> s(n);
		for(auto &si : s) cin >> si;
		
		map<string, vector<int>> m;
		for(int i=0; i < n; i++)
			m[s[i]].push_back(i);
		
		while(q--) {
			int x, y;
			cin >> x >> y;
			
			x--, y--;
			
			if (y < x)
				swap(x, y);
				
			if (s[y] != cant[s[x]]) {
				cout << y - x << endl;
				continue;
			}
			
			int a = 1e9, b = 1e9;
			
			for(auto &[c, v] : m) {
				if (c == s[x] || c == s[y])
					continue;
				
				auto lb = lower_bound(v.begin(), v.end(), x);
				auto ub = upper_bound(v.begin(), v.end(), x);
				
				if (lb != v.begin()) {
					lb = prev(lb);
					
					a = min(a, abs(x - *lb) + abs(y - *lb));
				}
				
				if (ub != v.end()) {
					b = min(b, abs(*ub - x) + abs(*ub - y));
				}
			}
			
			int ans = min(a, b);
			
			if (ans == 1e9)
				cout << -1 << endl;
			else
				cout << ans << endl;
		}
	}
}