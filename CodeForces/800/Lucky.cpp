#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    int sum_a = (int)s[0] + (int)s[1] + (int)s[2] - 48 * 3;
    int sum_b = (int)s[5] + (int)s[4] + (int)s[3] - 48 * 3;

    if (sum_a != sum_b)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
}