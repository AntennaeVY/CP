#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    cin >> a[0];

    bool ordered = true;

    for (int i = 1; i < n; i++) {
      cin >> a[i];

      if (a[i] <= a[i - 1]) ordered = false;
    }

    if (ordered) {
      cout << 0 << endl;
      continue;
    }

    bool good = true;
    int cnt = 0;

    for (int i = n - 1; i > 0; i--) {
      if (a[i] > a[i - 1]) continue;

      if (a[i] == 0) {
        good = false;
        break;
      }

      while (a[i - 1] >= a[i]) {
        a[i - 1] /= 2;
        cnt++;
      }
    }

    if (good) {
      cout << cnt << endl;
    } else {
      cout << -1 << endl;
    }
  }
}