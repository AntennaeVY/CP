#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, minX = 0, maxX = 0, minY = 0, maxY = 0;
    cin >> n;

    while (n--) {
      int x, y;
      cin >> x >> y;

      minX = min(x, minX);
      minY = min(y, minY);
      maxX = max(x, maxX);
      maxY = max(y, maxY);
    }

    cout << 2 * (maxX + maxY + abs(minX) + abs(minY)) << endl;
  }
}