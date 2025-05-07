#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<vector<int>> a(n, vector<int>(m));
		
		for(auto &ai : a)
			for(auto &aij : ai)
				cin >> aij;

		vector<pair<long long, int>> sum(n);
		
		for(int i=0; i < n; i++) {
			sum[i] = {0LL, i};
			
			for(int j=0; j < m; j++) {
				sum[i].first += a[i][j];
			}
		}
		
		sort(sum.rbegin(), sum.rend());
		
		long long ans = 0;
		
		for(int i=0; i < n; i++) {
			int x = sum[i].second;
			
			for(int j=0; j < m; j++) {
				ans += 1LL * (m*n - (m*i + j)) * a[x][j];
			}
		}

		cout << ans << endl;
	}
}