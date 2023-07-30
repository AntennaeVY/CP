#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long w, h;
    cin >> w >> h;

    vector<long long> s(4);

    for (int i{}; i < 4; i++) {
      long long k, mn = LLONG_MAX, mx = LLONG_MIN;
      cin >> k;

      for (int j{}; j < k; j++) {
        long long p;
        cin >> p;

        mn = min(mn, p);
        mx = max(mx, p);
      }

      s[i] = mx - mn;
    }

    long long ans = 0;

    for (int i{}; i < 4; i++) {
      if (i < 2)
        ans = max(ans, s[i] * h);
      else
        ans = max(ans, s[i] * w);
    }

    cout << ans << endl;
  }
}