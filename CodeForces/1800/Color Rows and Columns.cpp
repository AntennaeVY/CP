#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;
constexpr int MAXN = 1e3 + 5;
constexpr int MAXK = 100 + 5;

int dp[MAXK];
int cost[2 * MAXK];

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= k; i++) {
      dp[i] = INF;
    }

    dp[0] = 0;

    while (n--) {
      int a, b;
      cin >> a >> b;

      int total = a + b;

      for (int i = 1; i <= total; i++) {
        if (a > b) swap(a, b);
        cost[i] = cost[i - 1] + a;
        b--;
      }

      for (int i = k; i > 0; i--)
        for (int j = 1; j <= min(i, total); j++)
          dp[i] = min(dp[i], dp[i - j] + cost[j]);
    }

    if (dp[k] == INF)
      cout << -1 << endl;
    else
      cout << dp[k] << endl;
  }
}