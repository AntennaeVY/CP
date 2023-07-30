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

    bool ok = true;

    for (int i = 1; i < n; i++) {
      if (s[i] < s[i - 1]) ok = false;
    }

    if (ok) {
      cout << s << endl;
      continue;
    }

    int z = 0, o = 0;

    for (int i{}; i < n; i++) {
      if (s[i] != '0') break;

      z++;
    }

    for (int i = n - 1; i >= 0; i--) {
      if (s[i] != '1') break;

      o++;
    }

    cout << string(z + 1, '0') << string(o, '1') << endl;
  }
}