#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<string> grid(n);
	for(auto &gi : grid) cin >> gi;
	
	vector<int> ambiguous(m, 0);
	
	for(int i=1; i < n; i++) {
		for(int j=1; j < m; j++) {
			ambiguous[j] += grid[i-1][j] == 'X' && grid[i][j-1] == 'X';
		}
	}
	
	for(int j=0; j < m-1; j++) {
		ambiguous[j+1] += ambiguous[j];
	}
	
	int q;
	cin >> q;
	
	while(q--) {
		int x1, x2;
		cin >> x1 >> x2;
		
		x1--, x2--;
	
		bool ok = (ambiguous[x2] == ambiguous[x1]);
		
		cout << (ok ? "YES" : "NO") << endl;
	}
}