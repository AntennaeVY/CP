#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;

    if (rb == rd || cb == cd) {
      cout << 0 << endl;
      continue;
    }

    int ans = 1e5;

    if (rb < rd)
      ans = min(ans, rd - rb);
    else
      ans = min(ans, n - rb + (n - rd));

    if (cb < cd)
      ans = min(ans, cd - cb);
    else
      ans = min(ans, m - cb + (m - cd));

    cout << ans << endl;
  }
}