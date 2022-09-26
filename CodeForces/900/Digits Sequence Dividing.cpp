#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;

  while (q--) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (n == 2 && s[1] <= s[0]) {
      cout << "NO" << endl;
      continue;
    }

    cout << "YES" << endl;
    cout << 2 << endl;
    cout << s[0] << " " << s.substr(1);

    cout << endl;
  }
}