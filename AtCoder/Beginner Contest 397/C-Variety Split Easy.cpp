#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	map<int, int> m1, m2;
	for(auto &ai : a) m2[ai]++;
	
	int ans = 0;
	
	for(int i=1; i < n; i++) {
		m1[a[i-1]]++;
		m2[a[i-1]]--;
		
		if (m2[a[i-1]] == 0)
			m2.erase(a[i-1]);
			
		ans = max(ans, int(m1.size()) + int(m2.size()));
	}
	
	cout << ans << endl;
}