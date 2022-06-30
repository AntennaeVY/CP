#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<string> a(n + 1);

  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
  }

  int q;
  cin >> q;
  vector<vector<int>> updates(n + 3, vector<int>(m + 2, 0)),
      prefix(n + 3, vector<int>(m + 3, 0));

  for (int i{}; i < q; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    updates[x1][y1] += 1;
    updates[x2 + 1][y2 + 1] += 1;
    updates[x1][y2 + 1] -= 1;
    updates[x2 + 1][y1] -= 1;
  }

  for (int i = 1; i < n + 2; i++) {
    for (int j = 1; j < m + 2; j++) {
      prefix[i][j] = prefix[i][j - 1] + prefix[i - 1][j] -
                     prefix[i - 1][j - 1] + updates[i][j];
    }
  }

  for (int i = 1; i < n + 1; i++) {
    for (int j{}; j < m; j++) {
      if (prefix[i][j + 1] % 2) {
        a[i][j] == '0' ? a[i][j] = '1' : a[i][j] = '0';
      }
    }
    cout << a[i] << endl;
  }
}