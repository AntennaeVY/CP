#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n,m;
		cin >> n >> m;
		
		vector<string> grid(n);
		for(int i=0; i < n; i++) {
			cin >> grid[i];
			
		}
		
		if (grid[0][0] == '1') {
			cout << -1 << endl;
			continue;
		}
		
		int ans = 0;
		
		for(int i=0; i < n; i++) {
			ans += count(grid[i].begin(), grid[i].end(), '1');
		}
		
		cout << ans << endl;
		
		for(int i=n-1; i >= 0; i--) {
			for(int j=m-1; j >= 0; j--) {
				if (grid[i][j] == '0')
					continue;
				
				if (j == 0){
					cout << i << " " << j+1 << " ";
					cout << i+1 << " " << j+1 << endl;
					continue;
				}
				
				cout << i+1 << " " << j << " ";
				cout << i+1 << " " << j+1 << endl;	 
			}
		}
	}
}