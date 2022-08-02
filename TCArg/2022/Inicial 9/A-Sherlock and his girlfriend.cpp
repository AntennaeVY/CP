#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> sieve(n + 2, 1);

  for (long long i = 2; i < (n + 2); i++) {
    if (sieve[i] == 2) continue;

    for (long long j = i * i; j < (n + 2); j += i) {
      sieve[j] = 2;
    }
  }

  if (n > 2)
    cout << 2 << endl;
  else
    cout << 1 << endl;

  for (int i = 2; i < n + 2; i++) {
    cout << sieve[i] << " ";
  }
}