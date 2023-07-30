#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> c(n), dp(x + 1, 0);
  for (auto &it : c) cin >> it;

  dp[0] = 1;

  for (auto i : c) {
    for (int j = i; j <= x; j++) {
      if (j - i >= 0) dp[j] = (dp[j] + dp[j - i]) % mod;
    }
  }

  cout << dp[x] << endl;
}