#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n + 2, 0);
    for (int i = 1; i < n + 1; i++) {
      cin >> a[i];
    }

    if (n == 1) {
      cout << a[1] << endl;
      continue;
    }

    long long u = 0;

    for (int i = 1; i < n + 2; i++) {
      u += abs(a[i] - a[i - 1]);
    }

    for (int i = 1; i < n + 1; i++) {
      if (i == 1 && a[i] > a[i + 1])
        u -= a[i] - a[i + 1];
      else if (i == n && a[i] > a[i - 1])
        u -= a[i] - a[i - 1];
      else if (i != 1 && i != n && a[i] > a[i - 1] && a[i] > a[i + 1])
        u -= min(a[i] - a[i - 1], a[i] - a[i + 1]);
    }

    cout << u << endl;
  }
}