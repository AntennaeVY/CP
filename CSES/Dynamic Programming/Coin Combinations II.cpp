#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

int main() {
  int n, x;
  cin >> n >> x;

  vector<int> c(n);
  for (auto &ci : c) cin >> ci;

  vector<int> dp(x + 1);
  dp[0] = 1;

  for (auto j : c)
    for (int i = j; i <= x; i++)
      dp[i] += dp[i - j], dp[i] %= mod;

  cout << dp[x] << endl;
}