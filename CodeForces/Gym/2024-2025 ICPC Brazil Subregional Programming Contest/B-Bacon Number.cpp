#include <bits/stdc++.h>
using namespace std;

constexpr int MAXM = 1e6 + 5;
constexpr int MAXN = 100 + 5;

vector<vector<int>> adj(MAXN, vector<int>(MAXN)), g(MAXM);

int main() {
  int N, M;
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    int n;
    cin >> n;

    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;

      if (g[x].size()) {
        adj[g[x].back()][i] = x;
        adj[i][g[x].back()] = x;
      }

      g[x].push_back(i);
    }
  }

  // for (int i = 1; i <= N; i++) {
  // for (int j = 1; j <= N; j++) {
  // cout << adj[i][j] << " ";
  // }
  // cout << endl;
  // }

  int q;
  cin >> q;

  while (q--) {
    int x, y;
    cin >> x >> y;

    bool can = false;
    vector<bool> to(N + 1);

    for (auto &v : g[y]) to[v] = true;

    for (auto &w : g[x]) {
      vector<bool> vis(N + 1);
      stack<int> s;

      auto dfs = [&](auto &&self, int u) -> void {
        vis[u] = true;
        s.push(u);

        if (to[u]) return;

        for (int i = 1; i <= N; i++) {
          if (vis[i] || !adj[u][i]) continue;

          self(self, i);

          if (to[s.top()]) return;
        }

        s.pop();
      };

      dfs(dfs, w);

      if (s.size()) {
        can = true;

        cout << s.size() + 1 << endl;

        int last = 0;
        
        vector<string> ans;

        ans.push_back(to_string(y));

        while (s.size()) {
          if (last) ans.push_back(to_string(adj[last][s.top()]));

          ans.push_back(to_string(s.top()));
          last = s.top();

          s.pop();
        }

        ans.push_back(to_string(x));

        reverse(ans.begin(), ans.end());

       	for(auto &ansi : ans)
       		cout << ansi << " ";
       	cout << endl;

        break;
      }
    }

    if (!can) {
      cout << -1 << endl;
      continue;
    }
  }
}
