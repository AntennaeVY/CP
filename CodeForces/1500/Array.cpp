#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  map<int, int> m;

  for (auto &x : a) cin >> x;

  int l = 0, dist = 0, mn = INT_MAX, i = -1, j = -1;

  for (int r{}; r < n; r++) {
    m[a[r]]++;

    if (m[a[r]] == 1) dist++;

    while (dist >= k) {
      if (m[a[l]] == 1) dist--;

      m[a[l]]--;
      l++;
    }

    if (l != 0 && dist == k - 1) {
      l--;
      m[a[l]]++;
      dist++;
    }

    if (dist == k && r - l + 1 < mn) {
      mn = r - l + 1;
      i = l + 1;
      j = r + 1;
    }
  }

  cout << i << " " << j << endl;
}