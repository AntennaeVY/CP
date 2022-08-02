#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int l = 0, r = 0, sum = 0, ans = -1;

    for (int r{}; r < n; r++) {
      sum += a[r];

      while (sum > s) {
        sum -= a[l++];
      }

      if (sum == s) ans = max(ans, r - l + 1);
    }

    if (ans == -1)
      cout << ans << endl;
    else
      cout << n - ans << endl;
  }
}