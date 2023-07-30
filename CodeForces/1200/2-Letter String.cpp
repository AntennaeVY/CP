#include <bits/stdc++.h>

#include <map>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<string> a(n);
    vector<int> s(27, 0);
    vector<int> e(27, 0);
    map<string, int> c;

    for (int i{}; i < n; i++) {
      string x;
      cin >> x;

      s[x[0] - 97]++;
      e[x[1] - 97]++;
      c[x]++;

      a[i] = x;
    }

    long long cnt = 0;

    for (int i{}; i < n; i++) {
      cnt += s[a[i][0] - 97] + e[a[i][1] - 97] - 2 * c[a[i]];
    }

    cout << cnt / 2 << endl;
  }
}