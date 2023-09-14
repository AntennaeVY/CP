#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("convention.in", "r", stdin);
  freopen("convention.out", "w", stdout);

  int n, m, c;
  cin >> n >> m >> c;

  vector<int> a(n);
  for (auto &ai : a) cin >> ai;
  
  sort(a.begin(), a.end());

  int l = -1, r = 1e9;
  while (l + 1 < r) {
    int mid = l + (r - l) / 2;

    int bus = 0, cow = 0, start = 0;

    while (cow < n) {
      if (cow == start) bus++;

      if (a[cow] - a[start] > mid)
        start = cow;
      else if (cow - start + 1 == c)
        start = ++cow;
      else
        cow++;
    }

    if (bus > m)
      l = mid;
    else
      r = mid;
  }

  cout << r << endl;
}