#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int m;
		cin >> m;
		
		vector<vector<int>> grid(2, vector<int>(m, 0));
		
		int up = 0, down = 0;
		
		for(int i=0; i < 2; i++) {
			for(int j=0; j < m; j++) {
				cin >> grid[i][j];
			}
		}
		
		for(int j=0; j < m; j++) {
			up += grid[0][j];
		}
		
		int ans = 1e9;
		
		for(int j=0; j < m; j++) {
			up -= grid[0][j];
			ans = min(ans, max(up, down));
			down += grid[1][j];				
		}
		
		cout << ans << endl;
	}
}