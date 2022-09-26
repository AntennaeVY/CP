#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, r, b;
    cin >> n >> r >> b;

    string ans = "", first = "";

    int u = r / (b + 1), v = r % (b + 1);

    for (int i = 0; i < v; i++) {
      ans += string(u + 1, 'R');
      ans += "B";
    }

    for (int i = 0; i < b - v; i++) {
      ans += string(u, 'R');
      ans += "B";
    }

    ans += string(u, 'R');

    cout << ans << endl;
  }
}
