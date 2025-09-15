#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		
		vector<int> a(n), b(m);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		int dx = upper_bound(b.begin(), b.end(), x) - b.begin();
		int dy = upper_bound(a.begin(), a.end(), y) - a.begin();
		
		cout << min(m, dx) + min(n, dy) << "\n";
	}
}