#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll w, h, n;
  cin >> w >> h >> n;

  ll l = 0, r = 0;
  bool good = false;

  for (int i = 0; !good; i++) {
    r = (1LL << i);

    if ((r / h) * (r / w) >= n) good = true;
  }

  r++;

  while (l + 1 < r) {
    ll mid = l + (r - l) / 2;

    if ((mid / h) * (mid / w) < n) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << r << endl;
}