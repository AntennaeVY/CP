#include <bits/stdc++.h>
using namespace std;
vector<bool> isprime(1e7, true);
vector<int> primes;

void sieve(int n) {
  isprime[0] = false;
  isprime[1] = false;

  for (long long i = 2; i <= n; i++) {
    if (!isprime[i]) continue;
    primes.push_back(i);
    for (long long j = i * i; j <= n; j += i) {
      isprime[j] = false;
    }
  }
}

int main() {
  sieve(1e6);
  int t;
  cin >> t;

  while (t--) {
    int d;
    cin >> d;

    long long num = 1, last = 1;

    for (int i{}; i < 2; i++) {
      last = *(lower_bound(primes.begin(), primes.end(), last + d));

      num *= last;
    }

    cout << num << endl;
  }
}