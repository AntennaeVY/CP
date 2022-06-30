#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  ll s;

  cin >> n >> s;

  vector<int> a(n);

  for (auto &it : a) cin >> it;

  int l = 0;
  ll sum = 0, ans = 0;

  for (int r{}; r < n; r++) {
    sum += a[r];

    while (sum >= s) {
      sum -= a[l];
      l++;
    }

    ans += l;
  }

  cout << ans << endl;
}