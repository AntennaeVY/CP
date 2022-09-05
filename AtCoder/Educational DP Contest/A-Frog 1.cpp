#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> h(N), dp(N + 1, 0);
  for (auto &it : h) cin >> it;

  dp[2] = abs(h[1] - h[0]);

  for (int i = 3; i <= N; i++) {
    dp[i] = min(dp[i - 1] + abs(h[i - 1] - h[i - 2]),
                dp[i - 2] + abs(h[i - 1] - h[i - 3]));
  }

  cout << dp[N] << endl;
}