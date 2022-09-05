#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> c(n);
  for (auto &it : c) cin >> it;

  vector<int> dp(x + 1, INT_MAX - 1);
  dp[0] = 0;

  for (int i = 1; i <= x; i++) {
    for (auto k : c) {
      if (i - k >= 0) {
        dp[i] = min(dp[i], dp[i - k] + 1);
      }
    }
  }

  if (dp[x] == INT_MAX - 1)
    cout << -1 << endl;
  else
    cout << dp[x] << endl;
}