#include<bits/stdc++.h>
using namespace std;

int main() {
		int t;
		cin >> t;
		
		while(t--) {
			int n,m;
			cin >> n >> m;
			
			vector<int> grid(n*m);
			
			for(int i=0; i < n; i++) {
				for(int j=0; j < m; j++) {
					grid[i*m + j] = max(grid[i*m + j], i + j);
					grid[i*m + j] = max(grid[i*m + j], i + m - (j+1));
					grid[i*m + j] = max(grid[i*m + j], n - (i+1) + j);
					grid[i*m + j] = max(grid[i*m + j], n - (i+1) + m - (j+1));
				}
			}
			
			sort(grid.begin(), grid.end());
			
			for(int i=0; i < n; i++) {
				for(int j=0; j < m; j++) {					
					cout << grid[i*m + j] << " ";
				}
			}
			
			cout << endl;
		}
}