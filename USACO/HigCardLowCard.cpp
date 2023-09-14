#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	set<int> b;
	for(int i=1; i <= 2*n; i++) {
		b.insert(i);
	}
	
	for(int i=0; i < n; i++) {
		b.erase(a[i]);
	}
	
	set<int> l, h;
	
	int i = 0;
	for(auto x : b) {
		if (i < n/2) l.insert(x);
		else h.insert(x);
		i++;
	}
	
	int ans = 0;
	
	for(int i=0; i < n/2; i++) {
		auto it = h.upper_bound(a[i]);
		
		if (it != h.end()) {
			ans++;
			h.erase(it);
		} else {
			h.erase(h.begin());
		}
	}
	
	for(int i=n/2; i < n; i++) {
		auto it = l.upper_bound(a[i]);
		
		if (it != l.begin()) {
			ans++;
			l.erase(prev(it));
		} else {
			l.erase(prev(l.end()));
		}
	}
	
	cout << ans << endl;
}