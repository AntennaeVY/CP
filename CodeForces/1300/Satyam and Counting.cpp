#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<vector<int>> p(2, vector<int>(n + 2, 0));
    for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;

      p[y][x] = 1;
    }

    long long ans = 0;

    for (int x = 0; x <= n; x++) {
      if (p[0][x] && p[1][x]) ans += n - 2;

      if (x == 0) continue;

      if (p[0][x] && p[1][x - 1] && p[1][x + 1]) ans++;

      if (p[1][x] && p[0][x - 1] && p[0][x + 1]) ans++;
    }

    cout << ans << endl;
  }
}