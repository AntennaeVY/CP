#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  int l = 0, ans = 1;

  for (int r = 1; r < n; r++) {
    while (a[r] <= a[r - 1] && l != r) {
      l++;
    }

    ans = max(ans, r - l + 1);
  }

  cout << ans << endl;
}