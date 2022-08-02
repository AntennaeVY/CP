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

    set<int> s;
    int ans = 0;

    for (int r = n - 1; r >= 0; r--) {
      if (s.count(a[r])) {
        break;
      }

      s.insert(a[r]);
      ans = r;
    }

    cout << ans << endl;
  }
}