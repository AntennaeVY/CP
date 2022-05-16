#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;
    map<int, int> x;

    bool ans = false, valid = false;
    int a, b, mx = -1;

    for (int i{}; i < n; i++) {
      int xi;
      cin >> xi;

      x[xi]++;
    }

    for (auto e = x.rbegin(); e != x.rend(); e = next(e)) {
      if (e->second >= k) {
        for (auto d = x.begin(); d != e.base(); d = next(d)) {
          if (d->second >= k) {
            for (int i = d->first; i <= e->first; i++) {
              if (x[i] < k) {
                valid = false;
                break;
              }
              valid = true;
              ans = true;
            };

            if (valid) {
              if (e->first - d->first > mx) {
                a = d->first;
                b = e->first;

                mx = b - a;
              }
            }
          }
        }
      }
    }

    if (ans) {
      cout << a << " " << b << endl;
    } else {
      cout << -1 << endl;
    }
  }
}