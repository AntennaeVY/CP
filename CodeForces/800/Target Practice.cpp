#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		vector<string> grid(10);
		for(auto &gi : grid) cin >> gi;
		
		int ans = 0;
		
		for(int i=0; i < 10; i++) {
			for(int j=0; j < 10; j++) {
				if (grid[i][j] != 'X')
					continue;
					
				int x = min(i+1, 10 - i);
				int y = min(j+1, 10 - j);
				
				ans += min(x, y);
			}
		}
		
		cout << ans << endl;
	}
}