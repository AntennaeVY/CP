#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> c(n), dp(x + 1, 0);
  for (auto &it : c) cin >> it;

  dp[0] = 1;

  for (int i = 1; i <= x; i++) {
    for (int j : c) {
      if (i - j >= 0) dp[i] = (dp[i] + dp[i - j]) % mod;
    }
  }

  cout << dp[x] << endl;
}