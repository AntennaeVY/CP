#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		vector<string> sudoku(9);
		
		for(int i=0; i < 9; i++) {
			cin >> sudoku[i];
			
			replace(sudoku[i].begin(), sudoku[i].end(), '8', '9');
			cout << sudoku[i] << endl;
		}
	}
}