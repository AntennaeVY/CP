#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, x, y;
    cin >> n >> x >> y;

    if (x == 0 && y == 0 || x != 0 && y != 0 || (n - 1) % max(x, y) != 0) {
      cout << -1 << endl;
      continue;
    }

    int cnt = max(x, y), last = 1;

    for (int i = 1; i < n; i++) {
      if (cnt--)
        cout << last << " ";
      else {
        last = i + 1;
        cnt = max(x, y);
        i--;
      }
    }

    cout << endl;
  }
}