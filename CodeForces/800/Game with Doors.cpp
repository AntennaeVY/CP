#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int l, r;
    cin >> l >> r;

    int L, R;
    cin >> L >> R;

    if (L < l) {
      swap(l, L);
      swap(r, R);
    }

    if (L == l) {
      if (R < r) swap(r, R);
    }

    if (L > r) {
      cout << 1 << endl;
      continue;
    }

    int ans = min(r, R) - L;
    
    ans += (l < L);
    ans += (R != r);
    
    cout << ans << endl;
  }
}