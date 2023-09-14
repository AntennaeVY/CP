#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		
		vector<vector<int>> 
		grid(n, vector<int>(m, 0));
		
		vector<vector<long long>>
		sum2d(n+1, vector<long long>(m+1, 0));
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				cin >> grid[i][j];
			}
		}
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				sum2d[i+1][j+1] = sum2d[i][j+1] + sum2d[i+1][j] - sum2d[i][j] + grid[i][j];
			}
		}
		
		if (sum2d[n][m] < k+1) {
			cout << -1 <<  endl;
			continue;
		}
		
		int ans = 1e9;
		
		for(int i=1; i <= n; i++) {
			for(int j=1; j <= m; j++) {
				if (grid[i-1][j-1] == 0)
					continue;
				
				int l=-1, r = n+m;
				
				while(l+1 < r) {
					int mid = l + (r-l)/2;
					
					int max_col = min(j + mid, m);
					int max_row = min(i + mid, n);
	
					int min_col = max(j - mid, 1);
					int min_row = max(i - mid, 1);

					long long total = sum2d[max_row][max_col];
					
					total -= sum2d[max_row][min_col-1];
					total -= sum2d[min_row-1][max_col];
					total += sum2d[min_row-1][min_col-1];
					
					if (total >= k+1)
						r = mid;
					else
						l = mid;
				}
			
				ans = min(ans, r);
			}
		}
		
		cout << ans << endl;
	}
}