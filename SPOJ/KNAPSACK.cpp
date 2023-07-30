#include <bits/stdc++.h>
using namespace std;

int main() {
  int S, N;
  cin >> S >> N;

  vector<int> size(N), value(N);
  vector<vector<int>> dp(N, vector<int>(S + 1));

  for (int i{}; i < N; i++) {
    cin >> size[i] >> value[i];
  }

  dp[0][0] = 0;

  for (int i = 1; i <= S; i++) {
    if (i - size[0] >= 0) dp[0][i] = value[0];
  }

  for (int i = 1; i < N; i++) {
    for (int j{}; j <= S; j++) {
      int chosen = 0;

      if (j - size[i] >= 0) chosen = dp[i - 1][j - size[i]] + value[i];

      dp[i][j] = max(chosen, dp[i - 1][j]);
    }
  }

  cout << dp[N - 1][S] << endl;
}