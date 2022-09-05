#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int x, y;
    cin >> x >> y;

    if (x == 0 && y == 0) {
      cout << 0 << endl;
      continue;
    }

    int ed = sqrt(x * x + y * y);

    if (ed * ed == x * x + y * y)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
}