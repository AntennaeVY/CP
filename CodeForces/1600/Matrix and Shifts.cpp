#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<string> A(n);
		for(auto &Ai : A) cin >> Ai;
		
		int cnt = 0;
		
		for(int i=0; i < n; i++) {
			cnt += count(A[i].begin(), A[i].end(), '1');
		}
		
		int mx = 0;
		vector<vector<bool>> vis(n, vector<bool>(n));
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < n; j++) {
				if (A[i][j] == '0' || vis[i][j])
					continue;
					
				int cur = 0, x = i, y = j;
				
				while(!vis[x][y]) {
					vis[x][y] = true;
					
					if (A[x][y] == '1')
						cur++;
						
					x = (x+1)%n, y = (y+1)%n;
				}
				
				mx = max(cur, mx);
			}
		}
		
		cout << cnt - mx + (n - mx) << endl;		
	}
}