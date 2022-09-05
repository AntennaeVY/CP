#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    if (abs(n) == 1) {
      cout << 2 << endl;
      continue;
    }

    if (abs(n) % 3 == 0)
      cout << abs(n) / 3 << endl;
    else
      cout << abs(n) / 3 + 1 << endl;
  }
}