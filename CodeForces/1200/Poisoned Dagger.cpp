#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool good(vector<ll> &a, ll &mid, ll &h) {
  ll sum = mid;

  for (ll i = 1; i < a.size(); i++) {
    sum += min(a[i] - a[i - 1], mid);
  }

  return sum >= h;
}

int main() {
  ll t;
  cin >> t;

  while (t--) {
    ll n, h;
    cin >> n >> h;

    vector<ll> a(n);
    for (auto &ai : a) cin >> ai;

    ll l = 0, r = h;

    while (r > l) {
      ll mid = l + (r - l) / 2;

      if (!good(a, mid, h))
        l = mid + 1;
      else
        r = mid;
    }

    cout << r << endl;
  }
}