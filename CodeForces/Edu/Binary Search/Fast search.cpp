#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &x : a) cin >> x;

  sort(a.begin(), a.end());

  int k;
  cin >> k;

  while (k--) {
    int x, y;
    cin >> x >> y;

    int l = -1, r = n, ans = 0;

    while (l + 1 < r) {
      int mid = l + (r - l) / 2;

      if (a[mid] < x)
        l = mid;
      else
        r = mid;
    }

    ans -= r;

    l = -1, r = n;

    while (l + 1 < r) {
      int mid = l + (r - l) / 2;

      if (a[mid] <= y)
        l = mid;
      else
        r = mid;
    }

    ans += l;
    cout << ans + 1 << " ";
  }
}