#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &it : a) cin >> it;

    int mx = INT_MIN;
    ll ans = 0;
    bool pos = a[0] > 0;

    for (int p = 0; p < n; p++) {
      if (pos && a[p] > 0 || !pos && a[p] < 0) {
        mx = max(mx, a[p]);
      } else {
        ans += mx;
        pos = !pos;
        mx = INT_MIN;
        p--;
      }
    }

    ans += mx;

    cout << ans << endl;
  }
}