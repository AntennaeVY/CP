#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  map<int, vector<int>> g_0, g_1;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;

    g_0[a].push_back(b);
    g_1[b].push_back(a);
  }

  vector<bool> vis(n + 1);

  function<void(int, map<int, vector<int>> &)> dfs;

  dfs = [&](int u, map<int, vector<int>> &g) {
    vis[u] = true;

    for (auto v : g[u]) {
      if (!vis[v]) dfs(v, g);
    }
  };

  dfs(1, g_0);

  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      cout << "NO\n" << 1 << " " << i << endl;
      return 0;
    }
  }

  vis.assign(n + 1, false);
  dfs(1, g_1);

  for (int i = 2; i <= n; i++) {
    if (!vis[i]) {
      cout << "NO\n" << i << " " << 1 << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
}