#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &ai : a) cin >> ai;

    bool ok = true;

    for (int i = 1; i < n; i++) {
      if (a[i] < a[i - 1]) ok = false;
    }

    if (ok) {
      cout << 0 << endl;
      continue;
    }

    int l = 0, r = n - 1, ans = 0;

    while (l < r) {
      if (a[l] != 1) {
        l++;
        continue;
      }

      if (a[r] != 0) {
        r--;
        continue;
      }

      if (a[l] == 1 && a[r] == 0) {
        a[r] = 1;
        a[l] = 0;

        ans++;
        l++;
        r--;
      }
    }

    cout << ans << endl;
  }
}