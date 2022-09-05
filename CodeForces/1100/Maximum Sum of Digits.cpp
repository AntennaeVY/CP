#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;

  long long x = 0;
  int sum = 0;

  while (x * 10 + 9 <= n) {
    x *= 10;
    x += 9;
    sum += 9;
  }

  long long y = n - x;

  while (y != 0) {
    sum += y % 10;
    y /= 10;
  }

  cout << sum << endl;
}