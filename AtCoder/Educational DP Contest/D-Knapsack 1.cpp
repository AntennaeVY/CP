#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, W;
  cin >> N >> W;

  vector<long long> w(N), v(N);
  vector<vector<long long>> dp(N + 1, vector<long long>(W + 1, 0));

  for (int i{}; i < N; i++) {
    cin >> w[i] >> v[i];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= W; j++) {
      long long take = 0;

      if (j - w[i - 1] >= 0) take = dp[i - 1][j - w[i - 1]] + v[i - 1];

      dp[i][j] = max(dp[i - 1][j], take);
    }
  }

  cout << dp[N][W] << endl;
}