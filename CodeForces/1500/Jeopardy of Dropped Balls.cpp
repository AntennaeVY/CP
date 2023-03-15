#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<int>> a;
	for(int i=0; i < n; i++) {
		vector<int> ai;
		
		for(int j=0; j < m; j++) {
			int aij;
			cin >> aij;
			
			ai.push_back(aij);
		}
		
		a.push_back(ai);
	}
			
	vector<int> c;
	for(int i=0; i < k; i++) {
		int ci;
		cin >> ci;
		
		c.push_back(ci);
	}
	
	for(int j=0; j < k; j++) {
		int x = 0, y = c[j]-1;
		
		while(x < n) {			
			if (a[x][y] == 1) {
				a[x][y] = 2;
				y++;
			} else if (a[x][y] == 3) {
				a[x][y] = 2;
				y--;
			} else {
				x++;
			}
		}
		
		cout << y+1 << " ";
	}
}