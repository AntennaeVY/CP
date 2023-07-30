#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &i : a) cin >> i;

    long double sum = 0;
    bool ans = false;

    for (int i{}; i < n; i++) {
      sum += a[i];
    }

    for (int i{}; i < n; i++) {
      if ((sum - a[i]) / (n - 1) == a[i]) ans = true;
    }

    cout << (ans ? "YES" : "NO") << endl;
  }
}