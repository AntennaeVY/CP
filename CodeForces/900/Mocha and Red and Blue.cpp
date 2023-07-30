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

    int cnt = 0;

    for (int i{}; i < n; i++) {
      cnt += (s[i] != '?');
    }

    if (!cnt) s[0] = 'R';

    for (int i = 1; i < n; i++) {
      if (s[i] == '?' && s[i - 1] != '?') s[i] = s[i - 1] ^ 'R' ^ 'B';
    }

    for (int i = n - 2; i >= 0; i--) {
      if (s[i] == '?' && s[i + 1] != '?') s[i] = s[i + 1] ^ 'R' ^ 'B';
    }

    cout << s << endl;
  }
}