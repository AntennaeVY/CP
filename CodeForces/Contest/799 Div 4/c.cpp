#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    vector<vector<char>> cb(8, vector<char>(8));
    int r = 0, c = 0;

    for (int i{}; i < 8; i++) {
      for (int j{}; j < 8; j++) {
        cin >> cb[i][j];
      }
    }

    for (int i = 1; i < 8; i++) {
      for (int j = 1; j < 8; j++) {
        if (cb[i][j] == '#' && cb[i - 1][j - 1] == '#' &&
            cb[i - 1][j + 1] == '#' && cb[i + 1][j - 1] == '#' &&
            cb[i + 1][j + 1] == '#') {
          r = i;
          c = j;
          break;
        }
      }
      if (r != 0 && c != 0) break;
    }

    cout << r + 1 << " " << c + 1 << endl;
  }
}