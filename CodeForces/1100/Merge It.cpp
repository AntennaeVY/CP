#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;

		array<int, 3> m = {0, 0, 0};
		
		for(int i=0; i < n; i++) {
			m[a[i]%3]++;
		}
		
		int ans = m[0];
		
		int p12 = min(m[1], m[2]);
		m[1] -= p12, m[2] -= p12, ans += p12;
		
		ans += m[2]/3;
		ans += m[1]/3;
		
		cout << ans << endl;
	}
}