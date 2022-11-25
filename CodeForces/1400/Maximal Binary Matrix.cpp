#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	if (k > n*n) {
		cout << -1 << endl;
		return 0;
	}
	
	vector<vector<int>> matrix(n, vector<int>(n, 0));
	
	for(int i=0; i < n; i++) {		
		for(int j=i; j < n; j++) {
			if (k > 1) {
				matrix[i][j] = 1;
				matrix[j][i] = 1;
			} 
			
			if (k == 1 && i == j)
				matrix[i][j] = 1; 
			else if (k == 1 && i != j)
				matrix[i+1][i+1] = 1;
			
			if (i != j && k > 1)
				k -= 2;
			else
				k -= 1;
		}
	}
	
	for(auto row : matrix) {
		for(auto col : row) {
			cout << col << " ";
		}
		
		cout << endl;
	}
}