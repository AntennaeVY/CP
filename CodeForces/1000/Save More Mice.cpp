#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> m(k);
		for(auto &mi : m) cin >> mi;
		
		sort(m.rbegin(), m.rend());
		
		int c = 0, ans = 0;
		for(int i=0; i < k; i++, ans++) {
			if (c >= m[i])
				break;
				
			c += (n - m[i]);
		}
		
		cout << ans << endl;
	}
}