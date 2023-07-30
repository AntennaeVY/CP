#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	
	bool some_gj_equals_max_bi = false;
	ll max_bi = 0, min_gj = 1e9, ans = 0;
	vector<ll> b(n), g(m);
	
	for(int i=0; i < n; i++) {
		cin >> b[i];
		
		max_bi = max(max_bi, b[i]);
		ans += b[i]*m;
	}
	
	for(int j=0; j < m; j++) {
		cin >> g[j];
		
		min_gj = min(min_gj, g[j]);
		ans += g[j] - max_bi;
		
		some_gj_equals_max_bi |= g[j] == max_bi;
	}
	
	if (max_bi > min_gj) {
		cout << -1 << endl;
		return 0;
	}
	
	sort(b.rbegin(), b.rend());
	
	if (!some_gj_equals_max_bi) 
		ans += (min_gj - b[1]) - (min_gj - b[0]);
		
	cout << ans << endl;
}