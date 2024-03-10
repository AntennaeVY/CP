#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("closing.in", "r", stdin);
  freopen("closing.out", "w", stdout);

  int n, m;
  cin >> n >> m;

  map<int, set<int>> graph;

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    graph[u].insert(v);
    graph[v].insert(u);
  }

  vector<bool> vis(n + 1, false), del(n + 1, false);

  function<void(int)> dfs;

  dfs = [&](int node) {
    vis[node] = true;

    for (auto child : graph[node])
      if (!vis[child]) 
      	dfs(child);
  };

  for (int i = 1; i <= n; i++) {
    int cnt = 0;

    for (int j = 1; j <= n; j++) {
      if (vis[j] || del[j]) 
      	continue;

      dfs(j);
      cnt++;
    }

    cout << (cnt == 1 ? "YES" : "NO") << endl;

    int node;
    cin >> node;

    del[node] = true;

    for (auto child : graph[node]) 
    	graph[child].erase(node);

    graph.erase(node);

    vis.assign(n+1, false);
  }
}
