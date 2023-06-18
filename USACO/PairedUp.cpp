#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);
	
	int N;
	cin >> N;
	
	map<int, int> m;
	for(int i=0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		
		m[y] += x;
	}	
	
	vector<int> a;
	for(auto &[mi, _] : m)
		a.push_back(mi);
		
	int ans = 0, i=0, j=a.size()-1;
	while(i < j) {
		int mn = min(m[a[i]], m[a[j]]);
		m[a[i]] -= mn, m[a[j]] -= mn;
		
		if (mn != 0)
			ans = max(ans, a[i] + a[j]);
		
		if (m[a[i]] == 0)
			i++;
			
		if (m[a[j]] == 0)
			j--;
	}
	
	if (i == j && m[i] != 0)
		ans = max(ans, a[i] + a[j]);
	
	
	cout << ans << endl;
}