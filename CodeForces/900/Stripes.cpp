#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		vector<string> grid(8);
		
		for(int i=0; i < 8; i++) {
			cin >> grid[i];
		}
		
		string match = "RRRRRRRR";
		bool ok = false;
		
		for(int i=0; i < 8; i++) {
			if (grid[i] == match)
				ok = true;
		}
		
		cout << (ok ? "R" : "B") << endl;
	}
}