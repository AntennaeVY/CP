#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<pair<int, int>> m;
	
	for(int i=0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		
		m.emplace_back(e, s);
	}
	
	sort(m.begin(), m.end());
	
	int c = m[0].first, ans = 1;
	
	for(int i=1; i < n; i++) {
		if (m[i].second >= c)
			c = m[i].first, ans++;
	}
	
	cout << ans << endl;
}