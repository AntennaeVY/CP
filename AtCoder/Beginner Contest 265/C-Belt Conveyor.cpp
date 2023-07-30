#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<pair<char, bool>>> g(H, vector<pair<char, bool>>(W));

  for (int i{}; i < H; i++) {
    for (int j{}; j < W; j++) {
      char x;
      cin >> x;

      g[i][j] = make_pair(x, false);
    }
  }

  int i{}, j{};

  while (true) {
    bool ans = false;

    if (g[i][j].second) {
      cout << -1 << endl;
      return 0;
    }

    char m = g[i][j].first;
    g[i][j].second = true;

    switch (m) {
      case 'U':
        if (i == 0) {
          ans = true;
          break;
        }
        i--;
        break;

      case 'D':
        if (i == H - 1) {
          ans = true;
          break;
        }

        i++;
        break;
      case 'L':
        if (j == 0) {
          ans = true;
          break;
        }

        j--;
        break;
      case 'R':
        if (j == W - 1) {
          ans = true;
          break;
        }

        j++;
        break;
    }

    if (ans) {
      cout << i + 1 << " " << j + 1 << endl;
      return 0;
    }
  }
}