#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<bool>> v(n, vector<bool>(n));
	
	for(int x=0; x < m; x++) {
		char t;
		cin >> t;
		
		int i, j;
		cin >> i >> j;
		
		i--, j--;
		
		if (t == 'N') {
			v[i][j] = true;

			if (i+2 < n && j+1 < n) {
				v[i+2][j+1] = true;
			}
			
			if (i+2 < n && j-1 >= 0) {
				v[i+2][j-1] = true;
			}
			
			if (i-2 >= 0 && j+1 < n) {
				v[i-2][j+1] = true;
			}
			
			if (i-2 >= 0 && j-1 >= 0) {
				v[i-2][j-1] = true;
			}
			
			if (j+2 < n && i+1 < n) {
				v[i+1][j+2] = true;
			}
			
			if (j+2 < n && i-1 >= 0) {
				v[i-1][j+2] = true;
			}
			
			if (j-2 >= 0 && i+1 < n) {
				v[i+1][j-2] = true;
			}
			
			if (j-2 >= 0 && i-1 >= 0) {
				v[i-1][j-2] = true;
			}
			
		} 
		
		if (t == 'R') {
			for(int k=0; i-k >= 0; k++) {
				v[i-k][j] = true;
			}
			
			for(int k=0; i+k < n; k++) {
				v[i+k][j] = true;
			}
			
			for(int k=0; j-k >= 0; k++) {
				v[i][j-k] = true;
			}
			
			for(int k=0; j+k < n; k++) {
				v[i][j+k] = true;
			}
		}
		
		if (t == 'Q') {
			for(int k=0; i-k >= 0; k++) {
				v[i-k][j] = true;
			}
			
			for(int k=0; i+k < n; k++) {
				v[i+k][j] = true;
			}
			
			for(int k=0; j-k >= 0; k++) {
				v[i][j-k] = true;
			}
			
			for(int k=0; j+k < n; k++) {
				v[i][j+k] = true;
			}
			
			// diag
			
			for(int k=0; i-k >= 0 && j-k >= 0; k++) {
				v[i-k][j-k] = true;
			}
			
			for(int k=0; i-k >= 0 && j+k < n; k++) {
				v[i-k][j+k] = true;
			}
			
			for(int k=0; i+k < n && j+k < n; k++) {
				v[i+k][j+k] = true;
			}
			
			for(int k=0; i+k < n && j-k >= 0; k++) {
				v[i+k][j-k] = true;
			}
		}
	}
	
	int ans = 0;
	for(int i=0; i < n; i++) {
		for(int j=0; j < n; j++) {
			ans += v[i][j];
		}
	}
	
	cout << ans << '\n';
}