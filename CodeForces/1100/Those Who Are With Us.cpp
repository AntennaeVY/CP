#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m;
		cin >> n >> m;
		
		vector<vector<int>> a(n, vector<int>(m));
		
		int mx = 0;
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				cin >> a[i][j];
				mx = max(mx, a[i][j]);
			}
		}
		
		int cnt = 0;
		map<int,int> rows, cols;
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				if (a[i][j] == mx) {
					rows[i]++;
					cols[j]++;
					cnt++;
				}
			}
		}
		
		bool can = false;
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				int c = rows[i] + cols[j] - (a[i][j] == mx);
				
				can |= (c == cnt);
			}
		}

		cout << (can ? mx-1 : mx) << "\n";
	}
}