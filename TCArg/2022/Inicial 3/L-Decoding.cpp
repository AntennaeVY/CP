#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int odd = !!(n % 2);
  string ans(1, s[0]);

  for (int i = 1; i < n; i++) {
    string temp = "";

    if (odd && i % 2 != 0 || !odd && i % 2 == 0) {
      temp = s[i];
      temp += ans;
      ans = temp;
    } else if (odd && i % 2 == 0 || !odd && i % 2 != 0)
      ans += s[i];
  }

  cout << ans << endl;
}