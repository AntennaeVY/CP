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

    int ans = 0, minI = -1, maxI = 0;

    for (int i = 1; i < n; i++) {
      if (a[i] == a[i - 1] && minI == -1) minI = i;

      if (a[i] == a[i - 1]) maxI = i;
    }

    if (minI == -1 || minI == maxI)
      ans = 0;
    else
      ans = max(1, maxI - minI - 1);

    cout << ans << endl;
  }
}