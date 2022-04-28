#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    int sum = 0;
    bool bad = false;

    if (s.back() == 'A') {
      cout << "NO" << endl;
      continue;
    }

    for (char x : s) {
      if (x == 'A')
        sum++;
      else if (x == 'B')
        sum--;

      if (sum < 0) {
        bad = true;
        break;
      }
    }

    if (bad) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}