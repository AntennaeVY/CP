#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
	
	int n, q;
	cin >> n >> q;
	
	vector<int> p(n);
	for(auto &pi : p) cin >> pi;
	
	sort(p.begin(), p.end());
	
	while(q--) {
		int a,b;
		cin >> a >> b;
		
		auto l = lower_bound(p.begin(), p.end(), a);
		auto r = lower_bound(p.begin(), p.end(), b);
		
		int cnt  = r - l;
			
		if (r != p.end() && *r == b)
			cnt++;
			
		cout << max(0, cnt) << endl;
	}
}