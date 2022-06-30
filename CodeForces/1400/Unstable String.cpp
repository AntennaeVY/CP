#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    int l = 0;
    int odd0 = 0, even0 = 0, odd1 = 0, even1 = 0;
    long long ans = 0;

    for (int r{}; r < s.size(); r++) {
      if (s[r] == '1' && r % 2 == 0)
        even1++;
      else if (s[r] == '1' && r % 2 == 1)
        odd1++;
      else if (s[r] == '0' && r % 2 == 0)
        even0++;
      else if (s[r] == '0' && r % 2 == 1)
        odd0++;

      while (even1 && odd1 || even0 && odd0 || even1 && even0 || odd0 && odd1) {
        if (s[l] == '1' && l % 2 == 0)
          even1--;
        else if (s[l] == '1' && l % 2 == 1)
          odd1--;
        else if (s[l] == '0' && l % 2 == 0)
          even0--;
        else if (s[l] == '0' && l % 2 == 1)
          odd0--;

        l++;
      }

      ans += r - l + 1;
    }

    cout << ans << endl;
  }
}