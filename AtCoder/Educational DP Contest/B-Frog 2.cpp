#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  vector<int> h(N), dp(N + 1, 0);
  for (auto &it : h) cin >> it;

  dp[2] = abs(h[1] - h[0]);

  for (int i = 3; i <= N; i++) {
    int best = INT_MAX;
    for (int j = 1; j <= K; j++) {
      if (i - j - 1 >= 0)
        best = min(dp[i - j] + abs(h[i - 1] - h[i - j - 1]), best);
    }

    dp[i] = best;
  }

  cout << dp[N] << endl;
}