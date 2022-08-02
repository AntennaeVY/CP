#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (auto &x : a) cin >> x;

  while (k--) {
    int x;
    cin >> x;

    int l = -1, r = n, mid = 0;
    while (l + 1 < r) {
      mid = l + (r - l) / 2;

      if (a[mid] < x)
        l = mid;
      else
        r = mid;
    }

    cout << r + 1 << endl;
  }
}