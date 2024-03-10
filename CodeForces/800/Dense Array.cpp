#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int x;
    cin >> x;

    int ans = 0;

    for (int i = 1; i < n; i++) {
      int y;
      cin >> y;

      int a = min(x, y), b = max(x, y);
      while (a * 2 < b) ans++, a *= 2;
      x = y;
    }

    cout << ans << endl;
  }
}