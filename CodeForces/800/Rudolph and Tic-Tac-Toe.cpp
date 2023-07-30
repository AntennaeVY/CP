#include<bits/stdc++.h>
using namespace std;

int main() {
	int t=1;
	cin >> t;
	
	while(t--) {
		char m[3][3];
		
		for(int i=0; i < 3; i++) {
			for(int j=0; j < 3; j++) {
				cin >> m[i][j];
			}
		}
		
		string ans = "DRAW";
		
		for(int i=0; i < 3; i++) {
			bool ok = true;
			
			for(int j=1; j < 3; j++) {
				if (m[i][j] != m[i][j-1] || m[i][j] == '.')
					ok = false;
			}
			
			if (ok)
				ans = string(1, m[i][0]);
		}
		
		for(int i=0; i < 3; i++) {
			bool ok = true;
			
			for(int j=1; j < 3; j++) {
				if (m[j][i] != m[j-1][i] || m[j][i] == '.')
					ok = false;
			}
			
			if (ok)
				ans = string(1, m[0][i]);
		}
		
		if (m[1][1] != '.' && (m[0][0] == m[1][1] && m[1][1] == m[2][2] || m[0][2] == m[1][1] && m[1][1] == m[2][0]))
			ans = string(1, m[1][1]);
			
		cout << ans << endl;
	}
}