#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string s, t, ans = "YES";
    cin >> s >> t;

    for (int i{}; i < n; i++) {
      if (s[i] == 'B' && t[i] == 'G' || s[i] == 'G' && t[i] == 'B') continue;

      if (s[i] != t[i]) {
        ans = "NO";
        break;
      }
    }

    cout << ans << endl;
  }
}