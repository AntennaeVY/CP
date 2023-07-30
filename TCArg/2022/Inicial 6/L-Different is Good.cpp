#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  map<char, int> m;

  int ans = 0;

  for (int i{}; i < n; i++) {
    char x;
    cin >> x;

    m[x]++;

    if (m[x] > 1) ans++;
  }

  if (m.size() == 26 && ans > 0 || n > 26)
    cout << -1 << endl;
  else
    cout << ans << endl;
}