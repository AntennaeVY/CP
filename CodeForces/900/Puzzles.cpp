#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<int> f(m);
	for(auto &fi : f) cin >> fi;
	
	sort(f.begin(), f.end());
	
	int ans = 1e9;
	
	for(int i=n-1; i < m; i++) {
		ans = min(ans, f[i] - f[i-n+1]);
	}
	
	cout << ans << endl;
}