#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	for(int _=1; _ <= t; _++) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		map<int, int> m;
		for(int i=0; i < n; i++) {
			m[a[i]]++;
		}
		
		vector<int> v;
		for(auto [x, c] : m) {
			if (c % 2)
				v.push_back(x);
		}
		
		sort(v.begin(), v.end());
		
		map<int, vector<int>> mods;
		for(int i=0; i < v.size(); i++) {
			mods[v[i] % k].push_back(v[i]);
		}
		
		int cnt = 0;
		
		for(auto [x, w] : mods) {
			cnt += w.size() % 2;
		}
		
		if (cnt >= 2) {
			cout << -1 << endl;
			continue;
		}
		
		int ans = 0;
		
		for(auto [x, w] : mods) {
			if (w.size() > 1 && w.size() % 2) {
				int mn = 1e9+10;
				
				vector<int> p(w.size()+1), s(w.size()+2);
				
				for(int i=1; i < w.size(); i++) {
					if (i % 2 == 0)
						p[i] = p[i-1];
					else
						p[i] = p[i-1] + (w[i] - w[i-1]) / k;
				}
				
				
				for(int i=w.size()-1; i >= 0; i--) {
					if (i % 2 == 0)
						s[i] = s[i+1];
					else
						s[i] = s[i+1] + (w[i+1] - w[i]) / k;
				}
				
				for(int i=0; i < w.size(); i+=2) {
					mn = min(mn, p[i] + s[i+1]);
				}
				
				ans += mn;
					
				continue;
			}
			
			for(int i=1; i < w.size(); i+=2) {
				ans += (w[i] - w[i-1]) / k;
			}
		}
		
		cout << ans << endl;
	}
}