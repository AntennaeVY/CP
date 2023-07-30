#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }

    vector<vector<int>> b(a);
    for (int i = 0; i < n; i++) {
      sort(b[i].begin(), b[i].end());
    }

    int p = -1, q = -1;
    bool ok = true;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] != b[i][j]) {
          if (p == -1)
            p = j;
          else if (q == -1)
            q = j;
        }
      }
    }

    for (int i = 0; i < n; i++) {
      if (p != -1 && q != -1) swap(a[i][p], a[i][q]);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] != b[i][j]) {
          ok = false;
        }
      }
    }

    if (p == -1 && q == -1) {
      cout << 1 << " " << 1 << endl;
      continue;
    }

    if (!ok) {
      cout << -1 << endl;
      continue;
    }

    cout << p + 1 << " " << q + 1 << endl;
  }
}