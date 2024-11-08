#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &ai : a) cin >> ai;

  int sum = accumulate(a.begin(), a.end(), 0);

  if (sum % 2) {
    cout << -1 << endl;
    return 0;
  }

  vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1, 0));

  sort(a.begin(), a.end());

  for (int i = 0; i <= n; i++) dp[i][0] = true;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum / 2; j++) {
      if (j - a[i - 1] >= 0)
        dp[i][j] = dp[i - 1][j] | dp[i - 1][j - a[i - 1]];
      else
        dp[i][j] = dp[i - 1][j];
    }
  }

  if (!dp[n][sum / 2]) {
    cout << -1 << endl;
    return 0;
  }

  int i = n, j = sum / 2;
  vector<bool> take(n);

  while (j != 0) {
    if (j - a[i - 1] >= 0 && dp[i - 1][j - a[i - 1]]) {
      take[i - 1] = true;

      j -= a[i - 1];
    }

    i--;
  }

  vector<int> alice, bob;

  for (int i = 0; i < n; i++) {
    if (take[i])
      bob.push_back(a[i]);
    else
      alice.push_back(a[i]);
  }

  int x = 0, y = 0, cnt_a = 0, cnt_b = 0;
  vector<int> ans;

  while (x < alice.size()) {
    ans.push_back(alice[x]);

    cnt_a += alice[x++];

    while (y < bob.size() && cnt_b < cnt_a) {
      ans.push_back(bob[y]);

      cnt_b += bob[y++];
    }
  }

  for (auto &ansi : ans) cout << ansi << " ";
  cout << endl;
}