#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		vector<vector<int>> m(2, vector<int>(2));
		
		cin >> m[0][0] >> m[0][1];
		cin >> m[1][0] >> m[1][1];
		
		bool can = false;
		
		for(int i=0; i < 4; i++) {
			// rotate +90: transpose & reverse
			swap(m[0][1], m[1][0]);
			swap(m[0][0], m[0][1]);
			swap(m[1][0], m[1][1]);
			
			// check
			can |= (m[0][0] < m[0][1] && m[0][0] < m[1][0]) &&
				   (m[0][1] < m[1][1]) &&
				   (m[1][0] < m[1][1]);
		}
		
		cout << (can ? "YES" : "NO") << endl;
	}
}