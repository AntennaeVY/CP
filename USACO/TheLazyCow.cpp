#include<bits/stdc++.h>
using namespace std;

#define fin cin
#define fout cout

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ifstream fin("lazy.in");
	ofstream fout("lazy.out");
	
	int n, k;
	fin >> n >> k;
	
	vector<vector<int>> grid(n, vector<int>(n));
	vector<vector<int>> p(n+1, vector<int>(n+1, 0));
	
	for(int i=0; i < n; i++) {
		for(int j=0; j < n; j++) {
			fin >> grid[i][j];
		}
	}
	
	for(int i=1; i <= n; i++) {
		for(int j=1; j <= n; j++) {
			p[i][j] = p[i][j-1] + grid[i-1][j-1];
		}
	}
	
	int ans = 0;
	
	for(int i=1; i <= n; i++) {
		for(int j=1; j <= n; j++) {
			int curr = p[i][min(n, j+k)] - p[i][max(0, j-k-1)];

			for(int x=1; x <= min(n-i, k); x++) {
				curr += p[min(n,i+x)][min(n,j+k-x)] - p[min(n,i+x)][max(0,j-k+x-1)];
			}
			
			for(int x=1; x <= min(i, k); x++) {
				curr += p[max(0,i-x)][min(n,j+k-x)] - p[max(0,i-x)][max(0,j-k+x-1)];
			}
			
			ans = max(ans, curr);
		}
	}
	
	fout << ans << endl;
}