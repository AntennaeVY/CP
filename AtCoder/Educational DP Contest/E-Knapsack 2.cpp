#include <bits/stdc++.h>
using namespace std;

#define int long long

constexpr int INF = 1e18;

main() {
  int N, W;
  cin >> N >> W;

  vector<int> w(N), v(N);
  int mxval = 0;

  for (int i{}; i < N; i++) {
    cin >> w[i] >> v[i];

    mxval += v[i];
  }

  vector<vector<int>> dp(N + 1, vector<int>(mxval + 1, 0));

  for (int i = 1; i <= mxval; i++) {
    dp[0][i] = INF;
  }

  for (int i = 0; i <= N; i++) {
    dp[i][0] = 0;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= mxval; j++) {
      if (j - v[i - 1] >= 0)
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  int ans = 0;

  for (int i{}; i <= N; i++) {
    for (int j{}; j <= mxval; j++) {
      if (dp[i][j] <= W) ans = j;
    }
  }

  cout << ans << endl;
}