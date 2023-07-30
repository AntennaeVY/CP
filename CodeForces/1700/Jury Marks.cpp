#include<bits/stdc++.h>
using namespace std;

int main() {
	int k, n;
	cin >> k >> n;
	
	vector<int> a(k), b(n), ps(k+1, 0);
	for(auto &ai : a) cin >> ai;
	for(auto &bi : b) cin >> bi;
	
	for(int i=1; i <= k; i++) {
		ps[i] = ps[i-1] + a[i-1];
	}
	
	set<int> s;
	for(int i=1; i <= k; i++) {
		s.insert(b[0] - ps[i]);
	}
	
	int ans = 0;
	for(auto &x : s) {
		set<int> t;
		
		for(int i=1; i <= k; i++) {
			t.insert(x + ps[i]);
		}
		
		bool ok = true;
		for(int i=0; i < n; i++) {
			ok &= t.count(b[i]);
		}
		
		ans += ok;
	}
	
	cout << ans << endl;
}