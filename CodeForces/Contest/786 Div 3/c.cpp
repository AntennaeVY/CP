#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;

  while (q--) {
    string s, t;
    cin >> s >> t;

    if (t == "a") {
      cout << 1 << endl;
      continue;
    }

    if (count(t.begin(), t.end(), 'a')) {
      cout << -1 << endl;
      continue;
    }

    cout << (1LL << s.size()) << endl;
  }
}