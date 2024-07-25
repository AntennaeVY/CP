#include <bits/stdc++.h>
using namespace std;

constexpr long double eps = 1e-9;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<long double> a(n);
    for (auto &ai : a) cin >> ai;

    reverse(a.begin(), a.end());
    while (a.size() && a.back() == 1) a.pop_back();
    reverse(a.begin(), a.end());

    n = a.size();

    bool can = true;

    for (int i = 0; i < n; i++) {
      if (a[i] == 1) can = false;

      a[i] = log(log(a[i]));
    }

    if (!can) {
      cout << -1 << endl;
      continue;
    }
    
    long long ans = 0;

    for (int i = 1; i < n; i++) {
      if (a[i-1] - a[i] > eps) {
        int cnt = 1 + (a[i - 1] - a[i] - eps) / log(2);

        ans += cnt;
        a[i] = a[i] + cnt * log(2);
      }
    }

    cout << ans << endl;
  }
}