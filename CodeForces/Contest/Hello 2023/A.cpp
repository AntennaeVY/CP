#include <bits/stdc++.h>
using namespace std;

int main() {
  int t = 1;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (count(s.begin(), s.end(), 'L') == n ||
        count(s.begin(), s.end(), 'R') == n) {
      cout << -1 << endl;
      continue;
    }

    for (int i = 1; i < n; i++) {
      if (s[i] == 'R' && s[i - 1] == 'L') {
        cout << i << endl;
        break;
      } else if (s[i] == 'L' && s[i-1] == 'R') {
      	cout << 0 << endl;
      	break;
      }
    }
  }
}