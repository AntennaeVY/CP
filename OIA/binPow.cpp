#include <iostream>
using namespace std;

long long binPow(long long n, long long m) {
  if (m == 0) return 1;

  if (m % 2)
    return n * binPow(n, m - 1);
  else
    return binPow(n, m / 2) * binPow(n, m / 2);
}

long long binPowIt(long long n, long long m) {
  if (m == 0) {
    return 1;
  }

  long long acc = 1;

  while (m) {
    if (m & 1) {
      acc = acc * n;
    }
    n = n * n;

    m >>= 1;  // ??
  }

  return acc;
}

int main() {
  long long n, m;
  cin >> n >> m;

  cout << binPow(n, m) << endl;
  cout << binPowIt(n, m);
}