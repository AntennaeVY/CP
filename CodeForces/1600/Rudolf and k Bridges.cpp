#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m, k, d;
		cin >> n >> m >> k >> d;
		
		vector<vector<int>> a(n, vector<int>(m));
		for(int i=0; i < n; i++)
			for(int j=0; j < m; j++)
				cin >> a[i][j];
				
				
		vector<long long> v(n, 0);
		
		for(int i=0; i < n; i++) {
			multiset<long long> ms;
			ms.insert(1);
			
			vector<long long> b(m, 1);
			
			for(int j=1; j < m; j++) {
				b[j] = *ms.begin() + a[i][j] + 1;
				ms.insert(b[j]);
				
				if (j >= d+1)
					ms.erase(ms.find(b[j-d-1]));
			}
			
			v[i] = b[m-1];
		}
		
		long long ans = 1e18, cost = 0;
		int l = 0;
		for(int r=0; r < n; r++) {
			cost += v[r];
				
			while(r-l+1 > k) {
				cost -= v[l];
				l++;
			}
			
			if (r-l+1 == k) {
				ans = min(ans, cost);
			}
		}
		
		cout << ans << "\n";
	}
}