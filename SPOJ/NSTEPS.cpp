#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  while (N--) {
    int x, y, ans;
    cin >> x >> y;

    if (x >= 2 && y == x) {
      cout << x * 2 - x % 2 << endl;
      continue;
    } else if (x >= 2 && y == x - 2) {
      cout << x * 2 - x % 2 - 2 << endl;
      continue;
    } else if ((x == 0 || x == 1) && y == x) {
      cout << x << endl;
      continue;
    }

    cout << "No Number" << endl;
  }
}