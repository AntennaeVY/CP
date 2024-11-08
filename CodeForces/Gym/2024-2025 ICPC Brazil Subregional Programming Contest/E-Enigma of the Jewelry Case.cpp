#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<vector<int>> g(n, vector<int>(n, 0));
	
	int sm = 1e9;
	
	for(int i=0; i < n; i++) {
		for(int j=0; j < n; j++) {
			cin >> g[i][j];
			
			sm = min(sm, g[i][j]);
		}
	}
	
	
	if (g[0][0] == sm) {
		cout << 0 << endl;
	} else if (g[0][n-1] == sm) {
		cout << 1 << endl;
	} else if (g[n-1][n-1] == sm) {
		cout << 2 << endl;
	} else {
		cout << 3 << endl;
	}
	
}