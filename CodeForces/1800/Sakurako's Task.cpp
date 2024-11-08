#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (auto &ai : a) cin >> ai;

    if (n == 1) {
      cout << (k <= a[0] ? k - 1 : k) << endl;
      continue;
    }

    long long gcd = a[0];

    for (int i = 1; i < n; i++)
    	gcd = __gcd(gcd, a[i]);

    long long sum = 0;

    for (int i = 1; i < n; i++) {
      if (k < gcd) {
        break;
      }

      k -= gcd - 1, sum += gcd;
    }

    cout << sum + k << endl;
  }
}