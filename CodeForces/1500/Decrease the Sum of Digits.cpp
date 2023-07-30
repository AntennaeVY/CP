#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll sum_of_dig(ll n) {
  ll sum = 0;
	
  for (ll i = 10, x = n; x != 0; i *= 10) {
    sum += x % 10;
    x /= 10;
  }
  
  return sum;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    ll n, s;
    cin >> n >> s;

    ll ans = 0;

    if (sum_of_dig(n) <= s) {
      cout << 0 << endl;
      continue;
    }

    for (ll i = 1, x = n; x != 0; i *= 10) {
      ans += (10 - x % 10) * i;
      x += 10;
      x /= 10;

      if (sum_of_dig(x) <= s) break;
    }

    cout << ans << endl;
  }
}