#include <bits/stdc++.h>
using namespace std;

int main() {
  map<string, int> m;

  int k = 0;

  for (int i{}; i < 26; i++) {
    for (int j{}; j < 26; j++) {
      char a = 'a' + i;
      char b = 'a' + j;

      if (a == b) continue;
      string str = {a, b};
      m[str] = ++k;
    }
  }

  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    cout << m[s] << endl;
  }
}