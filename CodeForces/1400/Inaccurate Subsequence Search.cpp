#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		
		vector<int> a(n), b(m);
		for(auto &ai : a) cin >> ai;
		for(auto &bi : b) cin >> bi;
		
		map<int, int> M;
		
		for(int i=0; i < m; i++) {
			M[b[i]]++;
		}
		
		int ans = 0;
		
		map<int, int> cnt;
		int l = 0, c = 0;
		
		for(int r=0; r < n; r++) {
			cnt[a[r]]++;
			
			if (cnt[a[r]] <= M[a[r]])
				c++;
				
			while(r - l + 1 > m) {
				cnt[a[l]]--;
				
				if (cnt[a[l]] < M[a[l]])
					c--;
					
				l++;
			}
			
			if (r - l + 1 == m) {
				ans += (c >= k);
			}
		}
		
		cout << ans << endl;
	}
}