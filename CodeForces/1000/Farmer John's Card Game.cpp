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
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		
		bool can = true;
		
		for(int i=0; i < n; i++) {
			for(int j=1; j < m; j++) {
				if ((a[i][j] % n) != (a[i][j-1] % n))
					can = false;
			}
		}
		
		if (!can) {
			cout << -1 << endl;
			continue;
		}
		
		vector<int> ans(n);
		
		for(int i=0; i < n; i++) {
			ans[a[i][0] % n] = i+1;
		}
		
		for(int i=0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}