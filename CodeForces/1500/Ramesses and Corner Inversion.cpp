#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
	
	for(int i=0; i < n; i++) {
		for(int j=0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	
	for(int i=0; i < n; i++) {
		for(int j=0; j < m; j++) {
			cin >> b[i][j];
		}
	}
	
	for(int i=1; i < n; i++) {
		for(int j=1; j < m; j++) {
			if (a[i][j] != b[i][j]) {
				a[0][0] ^= 1;
				a[0][j] ^= 1;
				a[i][0] ^= 1;
				a[i][j] ^= 1;
			}
		}
	}
	
	bool ok = true;
	
	for(int i=0; i < n; i++) {
		for(int j=0; j < m; j++) {
			ok &= a[i][j] == b[i][j];
		}
	}
	
	cout << (ok ? "Yes" : "No") << endl;
}