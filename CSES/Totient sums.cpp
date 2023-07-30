#include <math.h>

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  vector<long long> phi(10000001, 0);
  vector<long long> sieve(10000001, 0);
  vector<long long> prefix_sum(10000001, 0);

  for (long long i{}; i <= 1e7; i++) {
    phi[i] = i;
  }

  for (long long i = 2; i <= 1e7; i++) {
    prefix_sum[i] += prefix_sum[i - 1];

    if (sieve[i] == 1) {
      prefix_sum[i] += phi[i];
      continue;
    }

    phi[i] = i - 1;
    prefix_sum[i] += phi[i];

    for (long long j = 2 * i; j <= 1e7; j += i) {
      phi[j] /= i;
      phi[j] *= i - 1;

      sieve[j] = 1;
    }
  }

  while (T--) {
    int a, b;
    cin >> a >> b;

    cout << prefix_sum[b] - prefix_sum[a] + phi[a] << endl;
  }
}