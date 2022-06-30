#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  map<int, int> m;

  for (auto &it : a) cin >> it;

  int l = 0, dis = 0;
  ll ans = 0;

  for (int r{}; r < n; r++) {
    m[a[r]]++;

    if (m[a[r]] == 1) dis++;

    while (dis > k) {
      m[a[l]]--;

      if (m[a[l]] == 0) dis--;

      l++;
    }

    ans += r - l + 1;
  }

  cout << ans << endl;
}