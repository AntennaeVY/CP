#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &i : a) cin >> i;

    long long sum = 0;

    for (int i{}; i < n; i++) {
      sum += max(a[i] - 1, m - a[i]);
    }

    cout << sum << endl;
  }
}