#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
  cout << fixed << setprecision(6);
  int n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (auto &x : a) cin >> x;

  ld l = 1e-6, r = 1e7 + 1;

  for (int i{}; i < 70; i++) {
    ld mid = l + (r - l) / 2;
    ll sum = 0;

    for (auto x : a) sum += floor(x / mid);

    if (sum >= k)
      l = mid;
    else
      r = mid;
  }

  cout << l << endl;
}