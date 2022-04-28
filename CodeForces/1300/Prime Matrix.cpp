#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n, vector<int>(m, 0));
  vector<unsigned long long> sieve(100001), primes;
  long long ans = 9e18;

  for (unsigned long long i = 2; i <= 100003; i++) {
    if (sieve[i]) continue;

    primes.push_back(i);

    for (unsigned long long j = 2 * i; j <= 100003; j += i) {
      sieve[j] = 1;
    }
  }

  for (int i{}; i < n; i++) {
    for (int j{}; j < m; j++) {
      cin >> a[i][j];
    }
  }

  for (int i{}; i < n; i++) {
    long long sum = 0;
    for (int j{}; j < m; j++) {
      auto nxt = lower_bound(primes.begin(), primes.end(), a[i][j]);
      long long cnt = *nxt - a[i][j];

      sum += cnt;
    }

    ans = min(ans, sum);
  }

  for (int i{}; i < m; i++) {
    long long sum = 0;
    for (int j{}; j < n; j++) {
      auto nxt = lower_bound(primes.begin(), primes.end(), a[j][i]);
      long long cnt = *nxt - a[j][i];

      sum += cnt;
    }

    ans = min(ans, sum);
  }

  cout << ans;
}