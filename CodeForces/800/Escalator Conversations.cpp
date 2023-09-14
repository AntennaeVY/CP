#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m, k, H;
		cin >> n >> m >> k >> H;
		
		vector<int> h(n);
		for(auto &hi : h) cin >> hi; 
		
		int ans = 0;
		
		for(int i=0; i < n; i++) {
			int diff = abs(h[i] - H);
			
			if (diff % k == 0 && diff / k > 0 && diff / k < m)
				ans++;
		}
		
		cout << ans << endl;
	}
}