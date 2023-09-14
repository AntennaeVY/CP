#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int s;
    cin >> s;
    long long p = 1, ans = 0;

    while (s) {
      ans += (s % 10) * p;
      p *= 10, s /= 10;
    }

    ans -= 1 * (p/10);

    cout << ans << endl;
  }
}