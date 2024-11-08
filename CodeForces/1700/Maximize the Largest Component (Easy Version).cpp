#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  for(int _=1; _<=t; _++) {
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    
    for(int i=0; i < n; i++)
    	cin >> grid[i];
    	
    vector<vector<bool>> vis(n+1, vector<bool>(m+1, false));
    vector<int> row(n+3, 0), col(m+3, 0), rowe(row), cole(col);

	int k = 1, minr = 0, maxr = 0, minc = 0, maxc = 0;

    auto dfs = [&](auto &&self, int i, int j) -> int {
		if (i < 0 || i >= n)
			return 0;
			
		if (j < 0 || j >= m)
			return 0;
			
		if (vis[i][j])
			return 0;
			
		if (grid[i][j] == '.')
			return 0;
		
		vis[i][j] = true;
		
		minr = min(minr, i), maxr = max(maxr, i);
		minc = min(minc, j), maxc = max(maxc, j);
		
		int cnt = 1;
		cnt += self(self, i+1, j);
		cnt += self(self, i, j+1);
		cnt += self(self, i-1, j);
		cnt += self(self, i, j-1);
		
		return cnt;
    };
    
    for(int i=0; i < n; i++) {
    	for(int j=0; j < m; j++) {
    		rowe[i+1] += (grid[i][j] == '.');
    		cole[j+1] += (grid[i][j] == '.');
    		
    		if (grid[i][j] == '.' || vis[i][j])
    			continue;
    			
    		minr = i, maxr = i;
    		minc = j, maxc = j;
    		
    		int size = dfs(dfs, i, j);
    		
    		row[minr] += size, row[maxr+3] -= size;
    		col[minc] += size, col[maxc+3] -= size;
    	}
    }
    
    for(int i=1; i <= n; i++)
    	row[i] += row[i-1];
    	
    for(int j=1; j <= m; j++)
    	col[j] += col[j-1];
    
    int ans = 0;
    
    for(int i=1; i <= n; i++)
    	ans = max(ans, rowe[i] + row[i]);
    
    for(int j=1; j <= m; j++)
    	ans = max(ans, cole[j] + col[j]);
    
    
    cout << ans << endl;
    
  }
}