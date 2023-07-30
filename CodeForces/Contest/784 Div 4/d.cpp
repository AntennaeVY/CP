#include <bits/stdc++.h>

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string s, c;
    cin >> s;

    int w = count(s.begin(), s.end(), 'W');
    if (w == n) {
      cout << "YES" << endl;
      continue;
    }

    stringstream S(s);

    bool good = true;

    while (getline(S, c, 'W')) {
      if (c.size() > 0 && (count(c.begin(), c.end(), 'R') <= 0 ||
                           count(c.begin(), c.end(), 'B') <= 0)) {
        good = false;
        break;
      }
    }

    if (good)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}