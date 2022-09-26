#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    set<char> t;

    for (auto c : s) t.insert(c);

    int cc = t.size(), ss = s.size();
    bool flag = true;

    if (cc == 1 || cc == ss) {
      cout << "YES" << endl;
      continue;
    }

    string a = s.substr(0, cc);
    int l = cc;

    for (int i{}; i < ss / cc; i++) {
      string b = s.substr(l, min(cc, ss - l));

      if (a != b) {
        for (int j{}; j < b.size(); j++)
          if (a[j] != b[j]) flag = false;
      }

      l += cc;
    }

    cout << (flag ? "YES" : "NO") << endl;
  }
}