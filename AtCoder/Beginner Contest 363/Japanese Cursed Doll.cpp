#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, t, p;
	cin >> n >> t >> p;
	
	vector<int> l(n);
	for(auto &li : l) cin >> li;
	
	sort(l.rbegin(), l.rend());
	
	int ans = 0;
	
	for(int i=0; i < p; i++) {
		ans = max(ans, t - l[i]);
	}
	
	cout << ans << endl;
}