#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    long long sum = 0;

    for (int i{}; i < n - 1; i++) {
      int swp = abs(b[i] - a[i + 1]) + abs(a[i] - b[i + 1]);
      int noswp = abs(a[i] - a[i + 1]) + abs(b[i] - b[i + 1]);
      sum += min(swp, noswp);
    }
    cout << sum << endl;
  }
}