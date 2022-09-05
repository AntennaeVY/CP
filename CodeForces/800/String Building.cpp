#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    if (s.size() == 1) {
      cout << "NO" << endl;
      continue;
    }

    bool ok = true;

    for (int i = 1; i < s.size() - 1; i++) {
      if (s[i] != s[i - 1] && s[i] != s[i + 1]) ok = false;
    }

    if (s[s.size() - 1] != s[s.size() - 2] || s[0] != s[1]) ok = false;

    cout << (ok ? "YES" : "NO") << endl;
  }
}