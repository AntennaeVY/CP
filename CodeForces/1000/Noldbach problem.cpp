#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  if (k == 0) {
    cout << "YES";
    return 0;
  }

  map<int, int> sieve;

  for (int i = 2; i <= n; i++) {
    if (sieve[i]) continue;

    for (int j = 2 * i; j <= n; j += i) {
      sieve[j] = i;
    }
  }

  vector<int> primes;

  for (auto x : sieve) {
    if (x.second == 0) primes.push_back(x.first);
  }

  for (size_t i = 1; i < primes.size(); i++) {
    if (k <= 0) {
      cout << "YES";
      return 0;
    }

    int prime = primes[i - 1] + primes[i] + 1;

    if (sieve[prime] == 0 && prime <= n) k--;
  }

  cout << "NO";
}