#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (auto &ai : a) cin >> ai;

  long long l = 0, r = 1e18;

  while (l + 1 < r) {
    long long x = l + (r - l) / 2;

    int j = 0;

    for (int i = k; i > 0; i--) {
      long long sum = 0;

      while (j <= n - i) {
        if (sum + a[j] > x) break;

        sum += a[j++];
      }
    }

    if (j == n)
      r = x;
    else
      l = x;
  }

  int j = 0;
  long long ans = 0;

  for (int i = k; i > 0; i--) {
    long long sum = 0;

    while (j <= n - i) {
      if (sum + a[j] > r) break;

      sum += a[j++];
    }
    
    ans = max(ans, sum);
  }
  
  cout << ans << endl;
}