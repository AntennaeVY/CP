#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int x, y;
    cin >> x >> y;

    string s;
    cin >> s;

    map<char, int> m;

    for (int i{}; i < s.size(); i++) {
      m[s[i]]++;
    }

    string ans = "YES";

    if ((y > 0 && m['U'] < y) || (y < 0 && m['D'] < abs(y)) ||
        (x > 0 && m['R'] < x) || (x < 0 && m['L'] < abs(x))) {
      ans = "NO";
    }

    cout << ans << endl;
  }
}