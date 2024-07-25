#include<bits/stdc++.h>
using namespace std;


int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main() {
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
		
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				
				bool ok = true;
				int mx = 0;
				
				for(auto [dx, dy] : d) {
					if (i + dx >= n || i + dx < 0)
						continue;
					
					if (j + dy >= m || j + dy < 0)
						continue;
						
					ok &= (a[i][j] > a[i+dx][j+dy]);
					mx = max(mx, a[i+dx][j+dy]);
				}
				
				if (!ok)
					continue;
					
				a[i][j] = mx;
			}
		}
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				cout << a[i][j] << " ";
			}
			
			cout << endl;
		}
	}
}