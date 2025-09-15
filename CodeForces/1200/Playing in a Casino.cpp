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
		
		vector<vector<int>> v(m, vector<int>(n));
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				cin >> v[j][i];
			}
		}
		
		for(int j=0; j < m; j++)
			sort(v[j].begin(), v[j].end());
			
		long long ans = 0;
			
		for(int j=0; j < m; j++) {
			long long sum = 0;
			
			for(int i=0; i < n; i++) {
				ans += 1LL*i*v[j][i] - sum;
				
				sum += v[j][i];
			}
		}
		
		cout << ans << endl;
	}
}