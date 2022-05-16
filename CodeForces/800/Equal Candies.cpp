#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    long long sum = 0, min = 1e7 + 1;

    for (int i{}; i < n; i++) {
      int a;
      cin >> a;

      min = a < min ? a : min;
      sum += a;
    }

    cout << sum - 1LL * n * min << endl;
  }
}