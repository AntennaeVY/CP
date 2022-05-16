#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, q;
    cin >> n >> q;

    long long sum = 0;

    vector<int> a(n);
    vector<long long> ps(n + 1, 0);

    for (int i{}; i < n; i++) {
      cin >> a[i];

      sum += a[i];
    }

    sort(a.rbegin(), a.rend());

    for (int i = 1; i <= n; i++) {
      ps[i] = ps[i - 1] + a[i - 1];
    }

    for (int i{}; i < q; i++) {
      long long xi;
      cin >> xi;

      if (xi > sum) {
        cout << -1 << endl;
        continue;
      }

      auto low = lower_bound(ps.begin(), ps.end(), xi);
      cout << (low - ps.begin() + 1) - 1 << endl;
    }
  }
}