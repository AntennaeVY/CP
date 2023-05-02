#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    map<pair<int, int>, int> m;
    array<int, 2> ans = {-1, n + 1};

    m[{0, 0}] = -1;
    int x = 0, y = 0;

    for (int i = 0; i < n; i++) {
      if (s[i] == 'L')
        x--;
      else if (s[i] == 'R')
        x++;
      else if (s[i] == 'D')
        y--;
      else
        y++;

      if (m.find({x, y}) != m.end() &&
          ans[1] - ans[0] + 1 > i - m[{x, y}] + 1) {
        ans = {m[{x,y}]+1, i};
      }

      m[{x, y}] = i;
    }

    if (ans[0] == -1)
      cout << -1 << endl;
    else
      cout << ans[0] + 1 << " " << ans[1] + 1 << endl;
  }
}