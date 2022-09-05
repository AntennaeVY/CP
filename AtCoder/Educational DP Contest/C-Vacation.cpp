#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<vector<int>> t(N, vector<int>(3));

  for (auto &x : t) {
    for (auto &y : x) {
      cin >> y;
    }
  }

  vector<vector<int>> dp(N, vector<int>(3, 0));

  for (int i{}; i < N; i++) {
    for (int j{}; j < 3; j++) {
      if (i == 0) {
        dp[i][j] = t[i][j];
        continue;
      }

      for (int k{}; k < 3; k++) {
        if (k == j) continue;
        dp[i][j] = max(dp[i][j], t[i][j] + dp[i - 1][k]);
      }
    }
  }

  int ans = 0;

  for (int i{}; i < 3; i++) {
    ans = max(ans, dp[N - 1][i]);
  }

  cout << ans << endl;
}