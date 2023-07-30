#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m, 0));

    long long max = -1;

    for (int i{}; i < n; i++) {
      for (int j{}; j < m; j++) {
        cin >> a[i][j];
      }
    }

    for (int i{}; i < n; i++) {
      for (int j{}; j < m; j++) {
        for (int k = 1; true; k++) {
          bool op = false;

          if (i + k < n && j + k < m) {
            op = true;
            b[i][j] += a[i + k][j + k];
          }

          if (i - k >= 0 && j - k >= 0) {
            op = true;
            b[i][j] += a[i - k][j - k];
          }

          if (i - k >= 0 && j + k < m) {
            op = true;
            b[i][j] += a[i - k][j + k];
          }

          if (i + k < n && j - k >= 0) {
            op = true;
            b[i][j] += a[i + k][j - k];
          }

          if (!op) {
            break;
          }
        }

        b[i][j] += a[i][j];

        max = b[i][j] > max ? b[i][j] : max;
      }
    }
    cout << max << endl;
  }
}