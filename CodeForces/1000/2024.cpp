#include <bits/stdc++.h>
#include <math.h>
using namespace std;

long long mod = 1e9 + 7;

long long binPow(long long x, long long n) {
  if (n == 0) return 1;

  long long acc = 1;

  while (n) {
    if (n & 1) acc = (acc % mod * x % mod) % mod;

    x = (x % mod * x % mod) % mod;
    n >>= 1;
  }

  return acc;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long n, x;
    cin >> n >> x;

    long long sum = (x % mod * (binPow(2, n) - 1) % mod) % mod;

    cout << sum << endl;
  }
}