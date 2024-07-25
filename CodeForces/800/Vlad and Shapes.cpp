#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<string> grid(n);
		
		for(auto &gi : grid) {
			cin >> gi;
		}
		
		for(int j=0; j < n; j++) {
			int sum = 0;
			
			for(int i=0; i < n; i++) {
				sum += grid[i][j] - 48;
			}
			
			if (sum == 1) {
				cout << "TRIANGLE" << endl;
				break;
			} else if (sum > 1) {
				cout << "SQUARE" << endl;
				break;
			}
		}
	}
}