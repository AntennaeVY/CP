#include <bits/stdc++.h>
using namespace std;

map<long long, int> cache;

int search(long long x) {
  if (cache.count(x)) return cache[x];

  int mn = __builtin_popcountll(x);

  long long factorial = 6;
  for (int i = 4; factorial <= x; i++) {
    mn = min(mn, 1 + search(x - factorial));

    factorial *= i;
  }

  cache[x] = mn;
  return mn;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long n;
    cin >> n;

    cout << search(n) << endl;
  }
}