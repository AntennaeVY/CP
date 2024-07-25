#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    for (auto &gi : g) cin >> gi;

    pair<int, int> d[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] != 'B') 
        	continue;

        for (auto [di, dj] : d) {
          if (i + di < 0 || i + di >= n) 
          	continue;

          if (j + dj < 0 || j + dj >= m) 
          	continue;

          if (g[i + di][j + dj] == '.') 
          	g[i + di][j + dj] = '#';
        }
      }
    }

    vector<vector<bool>> v(n, vector<bool>(m, false));

    function<void(int, int)> dfs;
    dfs = [&](int i, int j) {
      v[i][j] = true;

      for (auto [di, dj] : d) {
        if (i + di < 0 || i + di >= n) 
        	continue;

        if (j + dj < 0 || j + dj >= m) 
        	continue;

        if (v[i + di][j + dj] || g[i + di][j + dj] == '#')
        	continue;
    		
    	dfs(i + di, j + dj);
      }
    };
    
    
    if (g[n-1][m-1] == '.')
    	dfs(n-1, m-1);
    
    bool can = true;
    
    for(int i=0; i < n; i++) {
    	for(int j=0; j < m; j++) {
    		if (g[i][j] != 'G' && g[i][j] != 'B')
    			continue;
    		
    		can &= (g[i][j] == 'G' && v[i][j] || g[i][j] == 'B' && !v[i][j]);
    		
    		if (!can)
    			goto end;
    	}
    }
    
    end:
    cout << (can ? "Yes" : "No") << '\n';
  }
}