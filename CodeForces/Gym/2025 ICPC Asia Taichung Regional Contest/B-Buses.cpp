#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cout << setprecision(10);
	
	int n, m, l, x, y;
	cin >> n >> m >> l >> x >> y;
	
	vector<pair<int,int>> b(n);
	for(int i=0; i < n; i++) {
		cin >> b[i].first >> b[i].second;
	}
	
	vector<int> p(m);
	for(auto &pi : p) cin >> pi;
	
	vector<int> z(m);
	iota(z.begin(), z.end(), 0);
	
	sort(b.begin(), b.end());
	sort(z.begin(), z.end(), [&](auto i, auto j){
		if (p[i] < p[j])
			return true;
			
		return false;
	});
	
	vector<long double> best(n+1);
	best[0] = 1e18;
	
	for(int i=0; i < n; i++) {
		long double tx = (long double)(b[i].second - b[i].first) / x;
		long double ty = (long double)(l - b[i].second) / y;
		
		best[i] = min(best[i], tx + ty);
		best[i+1] = best[i];
	}
	
	vector<long double> ans(m);
	
	for(int i=0; i < m; i++) {
		auto ub = upper_bound(b.begin(), b.end(), make_pair(p[z[i]], (int)1e9+5));
		long double t = (long double)(l - p[z[i]]) / y;
		
		if (ub != b.begin()) {
			int j = prev(ub) - b.begin();
			
			t = min(t, best[j]);
		}
		
		ans[z[i]] = t;
	}
	
	for(auto &ansi : ans)
		cout << ansi << "\n";
}