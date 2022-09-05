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

    long long ans = 0;

    for (int i{}; i < n; i++) {
      if (s[i] == 'L')
        ans += i;
      else
        ans += n - 1 - i;
    }

    int l = 0, r = n - 1, k = 0;

    while (k != n && r >= l) {
      int changeL = 0, changeR = 0;

      if (n - 1 - l > l && s[l] == 'L') changeL = n - 1 - l - l;

      if (n - 1 - r < r && s[r] == 'R') changeR = r - (n - 1 - r);

      if (changeL > changeR) {
        ans += changeL;
        l++;
        k++;

        cout << ans << " ";
      } else if (changeR >= changeL && changeR != 0) {
        ans += changeR;
        r--;
        k++;

        cout << ans << " ";
      } else {
        l++;
        r--;
      }
    }

    for (int i = k; i < n; i++) cout << ans << " ";

    cout << endl;
  }
}