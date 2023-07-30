#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t=1;
	cin >> t;
	
	while(t--) {
		char grid[8][8];	
	
		for(int i=0; i < 8; i++) {
			for(int j=0; j < 8; j++) {
				cin >> grid[i][j];
			}
		}
		
		string word = "";
		
		for(int i=0; i < 8; i++) {
			for(int j=0; j < 8; j++) {
				if (grid[j][i] == '.')
					continue;
					
				word += grid[j][i];
			}
		}
		
		cout << word << endl;
 	}
}