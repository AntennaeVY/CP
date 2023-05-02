#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("paintbarn.in");
	ofstream fout("paintbarn.out");
	
	int n, k;
	fin >> n >> k;
	
	int grid[1003][1003];
	
	for(int i=0; i < 1003; i++)
		memset(grid[i], 0, 1003*sizeof(int));
		
	while(n--) {
		int x1, y1, x2, y2;
		fin >> x1 >> y1 >> x2 >> y2;
		
		x1++, y1++, x2++, y2++;
		
		grid[x1][y1] += 1;
		grid[x2][y1] += -1;
		grid[x1][y2] += -1;
		grid[x2][y2] += 1;
	}
	
	int ans = 0;
	
	for(int i=1; i < 1003; i++) {
		for(int j=1; j < 1003; j++) {
			grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
			
			if (grid[i][j] == k)
				ans++;
		}
	}
	
	fout << ans << endl;
}