#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  ll k;
  cin >> n >> k;

  vector<ll> a(n);

  for (auto &it : a) cin >> it;

  vector<ll> s1, s2;
  vector<ll> smin1 = {LLONG_MAX}, smax1 = {LLONG_MIN};
  vector<ll> smin2 = {LLONG_MAX}, smax2 = {LLONG_MIN};

  int l = 0;
  ll ans = 0, mn, mx;

  for (int r{}; r < n; r++) {
    s1.push_back(a[r]);

    smin1.push_back(min(smin1.back(), a[r]));
    smax1.push_back(max(smax1.back(), a[r]));

    mn = min(smin1.back(), smin2.back());
    mx = max(smax1.back(), smax2.back());

    while (mx - mn > k) {
      if (s2.empty()) {
        while (!s1.empty()) {
          s2.push_back(s1.back());
          smin2.push_back(min(s1.back(), smin2.back()));
          smax2.push_back(max(s1.back(), smax2.back()));

          s1.pop_back();
          smin1.pop_back();
          smax1.pop_back();
        }
      }

      s2.pop_back();
      smin2.pop_back();
      smax2.pop_back();

      mn = min(smin1.back(), smin2.back());
      mx = max(smax1.back(), smax2.back());

      l++;
    }

    ans += r - l + 1;
  }

  cout << ans << endl;
}