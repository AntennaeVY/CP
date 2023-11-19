#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;

    map<int, vector<int>> graph;

    for (int i = 0; i < n; i++) {
      int u, v;
      cin >> u >> v;

      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    if (a == b) {
      cout << "NO" << endl;
      continue;
    }

    int node = -1;
    vector<bool> vis(n + 1, false);

    function<bool(int, int)> dfs;
    dfs = [&](int u, int p) {
      if (vis[u]) {
        node = u;
        return true;
      }

      vis[u] = true;

      for (auto v : graph[u]) {
        if (v == p) continue;

        if (dfs(v, u)) return true;
      }

      return false;
    };

    function<int(int, int)> bfs;
    bfs = [&](int u, int v) {
      queue<int> q;
      q.push(u);

      int dist = 0;

      while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
          int x = q.front();
          q.pop();

          vis[x] = true;

          if (x == v) return dist;

          for (auto y : graph[x])
            if (!vis[y]) q.push(y);
        }

        dist++;
      }

      return dist;
    };

    dfs(b, -1);
    vis.assign(n + 1, false);

    int dist_a = bfs(a, node);
    vis.assign(n + 1, false);

    int dist_b = bfs(b, node);

    if (dist_b < dist_a)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}