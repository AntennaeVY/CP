#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n), b(n), mxi;

    int mx = -1, mxd = 0;
    bool equal = true;

    for (int i{}; i < n; i++) {
      cin >> a[i];
    }

    for (int i{}; i < n; i++) {
      cin >> b[i];

      if (b[i] != a[i]) {
        equal = false;
      }
    }

    bool good = true;

    for (int i{}; i < n; i++) {
      if (a[i] - b[i] < 0 && b[i] != 0) {
        good = false;
        break;
      }

      if (a[i] == b[i] && !equal) {
        good = false;
        break;
      }

      mxd = max(mxd, a[i] - b[i]);
    }

    if (good) {
      for (int i{}; i < n; i++) {
        if (a[i] - mxd < b[i] && b[i] != 0) {
          good = false;
          break;
        }
      }
    }

    if (good)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}