#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int L = 0, R = count(s.begin(), s.end(), '1');

    int ans = -1e9;

    for (int i = 0; i <= n; i++) {

      if (L >= (i + 1) / 2 && R >= (n - i + 1) / 2)
        ans = abs(n - 2 * i) < abs(n - 2 * ans) ? i : ans;

      if (i < n) L += s[i] == '0', R -= s[i] == '1';
    }

    cout << ans << endl;
  }
}