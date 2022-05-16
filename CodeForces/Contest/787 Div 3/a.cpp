#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    if (a < x)
      x -= a;
    else
      x = 0;

    if (b < y)
      y -= b;
    else
      y = 0;

    if (y + x > c)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}