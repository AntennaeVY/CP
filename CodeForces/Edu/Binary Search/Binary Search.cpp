#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n), q(k);
  for (auto &x : a) cin >> x;
  for (auto &x : q) cin >> x;

  for (auto x : q) {
    int l = 0, r = n - 1, ans = 0;
    while (l <= r) {
      int mid = l + (r - l) / 2;

      if (a[mid] == x) {
        ans = 1;
        break;
      } else if (a[mid] > x)
        r = mid - 1;
      else
        l = mid + 1;
    }

    if (ans)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}