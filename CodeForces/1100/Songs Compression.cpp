#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m;
  cin >> n >> m;

  vector<long long> a(n), b(n), t(n);
  long long sum = 0, best = 0;

  for (int i{}; i < n; i++) {
    cin >> a[i] >> b[i];

    sum += a[i];
    best += b[i];

    t[i] = i;
  }

  if (best > m) {
    cout << -1 << endl;
    return 0;
  }

  sort(t.begin(), t.end(), [&a, &b](const int &i, const int &j) {
    return (a[i] - b[i]) > (a[j] - b[j]);
  });

  int ans = 0;

  for (int i = 0; i < n; i++) {
    if (sum > m) {
      sum -= (a[t[i]] - b[t[i]]);
      ans++;
    } else
      break;
  }

  cout << ans << endl;
}