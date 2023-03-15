#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int a,b,k;
		cin >> a >> b >> k;
		
		vector<pair<int, int>> p(k);
		map<int, int> p_b, p_g;
		
		for(int i=0; i < k; i++) {
			cin >> p[i].first;
			p_b[p[i].first]++;
		}
		
		for(int i=0; i < k; i++) {
			cin >> p[i].second;
			p_g[p[i].second]++;
		}
		
		long long ans = 0;
		
		for(int i=0; i < k; i++) {
			ans += k - p_b[p[i].first] - p_g[p[i].second] + 1;
		}
		
		cout << ans/2 << endl;
	}
}