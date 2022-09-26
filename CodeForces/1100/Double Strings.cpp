#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<string> s(n);

    map<string, bool> m;

    for (int i{}; i < n; i++) {
      string x;
      cin >> x;

      s[i] = x;
      m[x] = true;
    }

    string ans = "";

    for (int j{}; j < n; j++) {
      bool ok = false;

      for (int i{}; i < s[j].size() - 1; i++) {
        string pf = s[j].substr(0, i + 1);
        string sf = s[j].substr(i + 1);

        if (m[pf] && m[sf]) ok = true;
      }
      if (ok)
        ans += "1";
      else
        ans += "0";
    }

    cout << ans << endl;
  }
}