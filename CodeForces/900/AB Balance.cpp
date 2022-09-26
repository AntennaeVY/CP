#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    if (s[0] == s.back())
      cout << s << endl;
    else
      cout << s.substr(0, s.size() - 1) << (char)(s.back() ^ 'a' ^ 'b') << endl;
  }
}