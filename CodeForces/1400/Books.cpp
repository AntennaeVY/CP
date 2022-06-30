#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t;
  cin >> n >> t;

  vector<int> a(n);
  for (auto &x : a) cin >> x;

  int l = 0, ans = 0;
  long long sum = 0;

  for (int r{}; r < n; r++) {
    sum += a[r];

    while (sum > t) {
      sum -= a[l];
      l++;
    }

    ans = max(ans, r - l + 1);
  }

  cout << ans << endl;
}