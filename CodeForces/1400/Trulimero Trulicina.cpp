#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, m, k;
		cin >> n >> m >> k;
		
		int N = 1, M = 1;
		
		for(int i=1; i <= n; i++) {
			if (n % i)
				continue;
			
			for(int j=1; j <= m; j++) {
				if (m % j)
					continue;
					
				if (i * j == k) {
					N = i, M = j;
				}
			}
		}
		
		// cout << N << " " << M << endl;
		
		vector<vector<int>> g(n, vector<int>(m));
		
		int c = 1;
		
		for(int i=0; i < N; i++) {
			for(int j=0; j < M; j++) {
				for(int l=i; l < n; l+=N) {
					for(int r=j; r < m; r+=M) {
						g[l][r] = c;
					}
				}
				
				c++;
			}
		}
		
		if (N == 1) {
			for(int i=1; i < n; i+=2) {
				for(int j=0; j < m; j++) {
					g[i][j] = g[i-1][(j-1 + M) % M];
				}
			}	
		}
		
		if (M == 1) {
			for(int j=1; j < m; j+=2) {
				for(int i=0; i < n; i++) {
					g[i][j] = g[(i-1 + N) % N][j-1];
				}
			}	
		}
		
		for(int i=0; i < n; i++) {
			for(int j=0; j < m; j++) {
				cout << g[i][j] << " ";
			}
			cout << endl;
		}
	}
}