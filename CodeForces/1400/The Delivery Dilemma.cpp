#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto &ai : a) cin >> ai;
    for (auto &bi : b) cin >> bi;

    vector<int> order(n);
    for (int i = 0; i < n; i++) {
      order[i] = i;
    }

    sort(order.begin(), order.end(),
         [&](const int &i, const int &j) { return a[i] < a[j]; });

    long long sum = 0;

    for (int i = 0; i < n; i++) {
      sum += b[i];
    }

    long long ans = sum, sub = 0;

    for (int i = 0; i < n; i++) {
      sub += b[order[i]];
      long long current = a[order[i]] + max((sum - sub) - a[order[i]], 0LL);

      ans = min(ans, current);
    }
    
    cout << ans << endl;
  }
}