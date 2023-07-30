#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    map<char, int> m;

    int l = 0, ans = INT_MAX;

    for (int r{}; r < s.size(); r++) {
      m[s[r]]++;

      while (m['1'] && m['2'] && m['3']) {
        ans = min(ans, r - l + 1);

        m[s[l]]--;
        l++;
      }
    }

    if (ans == INT_MAX) ans = 0;

    cout << ans << endl;
  }
}