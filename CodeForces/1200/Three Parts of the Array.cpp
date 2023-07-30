#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &x : a) cin >> x;

  int l = 0, r = n - 1;

  ll sum1 = 0, sum2 = 0, ans = 0;

  while (l <= r + 1) {
    if (sum1 > sum2) {
      sum2 += a[r--];
    } else if (sum1 < sum2) {
      sum1 += a[l++];
    } else {
      ans = max(ans, sum1);
      sum1 += a[l++];
      sum2 += a[r--];
    }
  }

  cout << ans << endl;
}