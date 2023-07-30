#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> r(n);
  for (auto &i : r) cin >> i;

  sort(r.rbegin(), r.rend());

  double ans = 0;

  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      ans += 4 * atan(1) * r[i] * r[i];
    else
      ans -= 4 * atan(1) * r[i] * r[i];
  }

  cout << ans << endl;
}