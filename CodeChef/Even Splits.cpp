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

    if (n == 2) {
      cout << s << endl;
      continue;
    }

    sort(s.begin(), s.end());

    cout << s << endl;
  }
}