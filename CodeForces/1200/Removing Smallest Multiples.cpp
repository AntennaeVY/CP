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

    vector<bool> m(n + 1);
    long long ans = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j += i) {
        if (s[j - 1] == '1') break;

        if (m[j])
          continue;
        else {
          m[j] = true;
          ans += i;
        }
      }
    }

    cout << ans << endl;
  }
}
