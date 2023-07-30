#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	vector<pair<int,int>> a;
	multiset<int> b;
	
	while(k--) b.insert(0);
	
	for(int i=0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		
		a.emplace_back(e, s);
	}
	
	sort(a.begin(), a.end());
	
	int ans = 0;
	
	for(int i=0; i < n; i++) {
		auto [e, s] = a[i];
		auto it = b.upper_bound(s);
		
		if (it == b.begin())
			continue;
			
		it = prev(it);
		
		if (*it <= s) {
			b.erase(it); 
			b.insert(e);
			
			ans++;
		}
	}
	
	cout << ans << endl;
} 