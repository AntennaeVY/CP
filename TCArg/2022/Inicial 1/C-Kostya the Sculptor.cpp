#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int mn = -1, num = 1, first = 0, second = 0;

  vector<vector<int>> a(n, vector<int>(3, 0));
  for (int i{}; i < n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];

    if (max(mn, min(a[i][0], min(a[i][1], a[i][2]))) > mn) {
      mn = max(mn, min(a[i][0], min(a[i][1], a[i][2])));
      first = i + 1;
    }
  }

  for (int i{}; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int sum = 0, cond = 0;
      vector<int> eq;

      for (int k{}; k < 3; k++) {
        for (int l{}; l < 3; l++) {
          if (a[i][k] == a[j][l]) {
            cond++;
            eq.push_back(a[i][k]);
          }

          if (cond == 3) {
            sum = a[i][0] * 2;
          } else if (cond == 2) {
            for (int x{}; x < 3; x++) {
              for (int y{}; y < 3; y++) {
                if (a[i][x] != a[j][y]) {
                  sum = a[i][x] + a[j][y];
                }
              }
            }
          }
        }
      }

      if (cond >= 2) {
        int mnx = -1;
        for (int x{}; x < eq.size(); x++) {
          mnx = max(mnx, min(eq[x], sum));
        }

        if (mnx > mn) {
          num = 2;
          first = i + 1;
          second = j + 1;

          mn = mnx;
        }
      }
    }
  }

  cout << num << endl;
  cout << first;

  if (num == 2) cout << " " << second;

  cout << endl;
}