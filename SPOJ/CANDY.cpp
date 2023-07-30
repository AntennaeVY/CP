#include <bits/stdc++.h>
using namespace std;

int main() {
  while (1) {
    int n;
    cin >> n;

    if (n == -1) break;

    int sum = 0;
    vector<int> a(n);

    for (int i{}; i < n; i++) {
      cin >> a[i];

      sum += a[i];
    }

    if (sum % n) {
      cout << -1 << endl;
      continue;
    }

    int ans = 0;
    sum /= n;

    for (int i{}; i < n; i++) {
      if (a[i] > sum) ans += a[i] - sum;
    }

    cout << ans << endl;
  }
}