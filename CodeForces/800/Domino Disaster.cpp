#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  map<char, char> m;

  m['L'] = 'L';
  m['R'] = 'R';
  m['U'] = 'D';
  m['D'] = 'U';

  while (t--) {
    int n;
    cin >> n;

    for (int i{}; i < n; i++) {
      char c;
      cin >> c;

      cout << m[c];
    }

    cout << endl;
  }
}