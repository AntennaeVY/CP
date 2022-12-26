#include<bits/stdc++.h>
using namespace std;

vector<string> grid(8);
vector<bool> col(8), diag1(8), diag2(8);
int ans = 0;

void search(int i = 0) {
	if (i == 8) {
		ans++;
		return;
	}
	
	for(int j=0; j < 8; j++) {
		if (col[j] || diag1[i+j] || diag2[i-j+7] || grid[i][j] == '*')
			continue;
			
		col[j] = diag1[i+j] = diag2[i-j+7] = 1;
		search(i+1);
		col[j] = diag1[i+j] = diag2[i-j+7] = 0;
	}
}

int main() {	
	for(int i=0; i < 8; i++) {
		cin >> grid[i];
	}
	
	search();
	cout << ans << endl;
}