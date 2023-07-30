#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int a, b;
    cin >> a >> b;

    int tries = 100, mn = INT_MAX, copyB = b;

    while (tries--) {
      int copyA = a;

      if (copyB == 1) copyB++;

      int cnt = copyB - b;

      while (copyA != 0) {
        copyA /= copyB;
        cnt++;
      }

      mn = min(cnt, mn);
      copyB++;
    }

    cout << mn << endl;
  }
}