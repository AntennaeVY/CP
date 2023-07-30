#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<char> r(n), b(n);
    for (auto &i : r) cin >> i;
    for (auto &i : b) cin >> i;

    int rp = 0, bp = 0;

    for (int i{}; i < n; i++) {
      if (r[i] > b[i])
        rp++;
      else if (r[i] < b[i])
        bp++;
      else
        rp++, bp++;
    }

    if (rp > bp)
      cout << "RED" << endl;
    else if (rp < bp)
      cout << "BLUE" << endl;
    else
      cout << "EQUAL" << endl;
  }
}