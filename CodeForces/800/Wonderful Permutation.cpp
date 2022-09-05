#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    int ans = 0;

    for (int i{}; i < n; i++) {
      cin >> p[i];

      if (p[i] > k && i < k) ans++;
    }

    if (k == n) {
      cout << 0 << endl;
      continue;
    }

    cout << ans << endl;
  }
}