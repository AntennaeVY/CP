#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (auto &ai : a) cin >> ai;

    vector<long long> p(n+1);

    for (int i = 0; i < n; i++) {
      p[i+1] = p[i] + a[i];
    }
    
    // p[j] > x + p[i]

    vector<int> dp(n);
    for (int i = n - 1; i >= 0; i--) {
      auto it = prev(upper_bound(p.begin(), p.end(), p[i] + x));
      int j = it - p.begin();
    
      dp[i] = j - i;

      if (j + 1 < n) 
      	dp[i] += dp[j + 1];
    }
    
    cout << accumulate(dp.begin(), dp.end(), 0LL) << endl;
  }
}