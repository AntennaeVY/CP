#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;

  int n;
  cin >> n;

  vector<string> a(n);
  for (auto &x : a) cin >> x;

  for (int i{}; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (a[i][1] == s[0] && a[j][0] == s[1] ||
          a[j][1] == s[0] && a[i][0] == s[1] || a[j] == s) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }

  cout << "NO" << endl;
}