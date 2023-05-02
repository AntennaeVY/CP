#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	
	vector<string> grid(n);
	vector<vector<int>> p(n+1, vector<int>(n+1, 0));
	
	for(int i=0; i < n; i++) {
		cin >> grid[i];
	}
	
	for(int i=1; i <= n; i++) {
		for(int j=1; j <= n; j++) {
			p[i][j] = p[i][j-1] + p[i-1][j] - p[i-1][j-1] + (grid[i-1][j-1] == '*');
		}
	} 
	
	while(q--) {
		int y1, x1, y2, x2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		cout << p[x2][y2] - p[x1-1][y2] - p[x2][y1-1] + p[x1-1][y1-1] << endl;
	}
}