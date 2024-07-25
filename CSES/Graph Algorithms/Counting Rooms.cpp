#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  vector<string> g(n);

  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }

  vector<vector<bool>> v(n, vector<bool>(m, false));

  int ans = 0;

  pair<int, int> d[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  function<void(int, int)> dfs;
  dfs = [&](int x, int y) {
    v[x][y] = true;

    for (auto [dx, dy] : d) {
      if (x + dx >= n || x + dx < 0) 
      	continue;

      if (y + dy >= m || y + dy < 0) 
      	continue;

      if (g[x + dx][y + dy] == '#' || v[x + dx][y + dy]) 
      	continue;
      	
      	dfs(x + dx, y + dy);
    }
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == '#' || v[i][j]) 
      	continue;

		dfs(i, j);

      	ans++;
    }
  }

  cout << ans << "\n";
}