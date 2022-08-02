#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin >> n >> a >> b;

  int ans = 0, v = 0;

  for (int i{}; i < n; i++) {
    int x;
    cin >> x;

    if (x == 1 && a != 0) {
      a--;
      continue;
    }

    if (x == 1 && a == 0 && b != 0) {
      b--;
      v++;
      continue;
    }

    if (x == 1 && a == 0 && b == 0 && v != 0) {
      v--;
      continue;
    }

    if (x == 1 && a == 0 && v == 0 && b == 0) {
      ans++;
      continue;
    }

    if (x == 2 && b != 0) {
      b--;
      continue;
    }

    if (x == 2 && b == 0) {
      ans += 2;
      continue;
    }
  }

  cout << ans;
}