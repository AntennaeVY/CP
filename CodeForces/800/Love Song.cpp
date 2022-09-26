#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q;
  cin >> n >> q;

  string s;
  cin >> s;

  vector<int> ln(n + 1);
  ln[0] = 0;

  for (int i = 1; i <= n; i++) {
    ln[i] = ln[i - 1] + (s[i - 1] - 96);
  }

  while (q--) {
    int l, r;
    cin >> l >> r;

    cout << ln[r] - ln[l - 1] << endl;
  }
}