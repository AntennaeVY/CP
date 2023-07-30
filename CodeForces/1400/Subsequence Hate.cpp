#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    string s;
    cin >> s;

    int ans = 1e9;
    int seen_ones = 0, seen_zeros = 0;
    int zeros = count(s.begin(), s.end(), '0');
    int ones = count(s.begin(), s.end(), '1');

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0')
        seen_zeros++;
      else
        seen_ones++;

      int cost1 = seen_zeros + ones - seen_ones;
      int cost0 = seen_ones + zeros - seen_zeros;

      ans = min(min(cost1, cost0), ans);
    }

    cout << ans << endl;
  }
}