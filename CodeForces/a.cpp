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

    if (n != 5) {
      cout << "NO" << endl;
      continue;
    }

    set<char> t = {'T', 'i', 'm', 'u', 'r'};

    string ans = "YES";

    for (char c : s) {
      if (t.count(c) == 0) {
        ans = "NO";
        break;
      } else {
        t.erase(c);
      }
    }

    cout << ans << endl;
  }
}