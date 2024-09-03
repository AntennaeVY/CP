#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 500 + 5;
constexpr int MAXW = 1e4 + 5;
constexpr long long INF = 1e18;

long long dp[MAXN][MAXW];

int main() {
  int t;
  cin >> t;

  while (t--) {
    int E, F;
    cin >> E >> F;

    int N;
    cin >> N;

    vector<int> P(N), W(N);
    for (int i = 0; i < N; i++) cin >> P[i] >> W[i];

    int M = F - E;

    for (int i = 0; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        dp[i][j] = INF;
      }
    }

    for (int i = 0; i <= N; i++) {
      dp[i][0] = 0;
    }

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
      	dp[i][j] = dp[i-1][j];
      	
      	if (j >= W[i-1])
        	dp[i][j] = min(P[i-1] + dp[i][j-W[i-1]], dp[i][j]);
      }
    }

    if (dp[N][M] == INF)
      cout << "This is impossible." << endl;
    else
      cout << "The minimum amount of money in the piggy-bank is " << dp[N][M]
           << "." << endl;
  }
}