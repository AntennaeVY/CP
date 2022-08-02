#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed << setprecision(10);
  double c;
  cin >> c;

  long double l = 1e-6, r = 10e5;

  for (int i{}; i < 60; i++) {
    long double mid = l + (r - l) / 2;

    if (mid * mid + sqrt(mid) >= c)
      r = mid;
    else
      l = mid;
  }

  cout << r << endl;
}