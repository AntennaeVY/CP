#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;

  int n = s.size(), m = t.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == t[j - 1])
        dp[i][j] = 1 + dp[i - 1][j - 1];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  int i = n, j = m;
  string ans;

  while (i >= 1 && j >= 1) {
    if (dp[i - 1][j] > dp[i][j - 1]) {
      i--;
      continue;
    } else if (dp[i][j - 1] > dp[i - 1][j]) {
      j--;
      continue;
    }

    if (dp[i - 1][j] == dp[i][j - 1] && dp[i][j] != dp[i - 1][j]) {
      ans.push_back(s[i - 1]);
      j--;
    }

    i--;
  }

  reverse(ans.begin(), ans.end());

  cout << ans << endl;
}