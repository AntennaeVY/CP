#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &it : a) cin >> it;

    vector<int> c(3, 0);
    for (int i{}; i < n; i++) {
      c[a[i] % 3]++;
    }

    int ans = 0;

    while (c[0] != c[1] || c[1] != c[2] || c[0] != c[2]) {
      for (int i = 0; i < 3; i++) {
        if (c[i] > n / 3) {
          c[(i + 1) % 3] += c[i] - n / 3;
          ans += c[i] - n / 3;

          c[i] -= c[i] - n / 3;
        }
      }
    }

    cout << ans << endl;
  }
}