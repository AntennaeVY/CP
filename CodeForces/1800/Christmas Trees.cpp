#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> x(n);
	map<ll, bool> used;
	map<int, pair<ll, ll>> mp;
	
	for(auto &xi : x) {
	    cin >> xi;
	    used[xi] = true;
	    mp[xi] = {xi-1, xi+1};
	}
	
	vector<ll> order;
	ll ans = 0;
	
	while(true) {
		bool ok = false;
		
		for(auto it = mp.begin(); it != mp.end(); it++) {
			int xi = it->first;
			ll &l = it->second.first, &r = it->second.second;
			
			if (used[l] && used[r]) {
				auto newit = prev(it);
				mp.erase(it);
				it = newit;
				continue;
			}
			
			if (!used[l]) {
				order.push_back(l);
				used[l] = true;
				
				ans += abs(xi - l);
				l -= 1;
				m -= 1;
				
			}
			
			if (m == 0) {
				ok = true;
				break;
			}
			
			if (!used[r]) {
				order.push_back(r);
				used[r] = true;
				
				ans += abs(xi-r);
				r += 1;
				m -= 1;
			}
			
			if (m == 0) {
				ok = true;
				break;
			}
			
		}
		
		if (ok)
			break;
	}
	
	cout << ans << endl;
	
	for(auto y : order)
		cout << y << " ";
}