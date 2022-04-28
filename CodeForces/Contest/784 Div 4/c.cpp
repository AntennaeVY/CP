#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i{}; i < n; i++) {
      cin >> a[i];
    }

    bool sol = true;

    for (int i = 2; i < n; i++) {
      if (a[i] % 2 != a[i - 2] % 2) {
        cout << "NO" << endl;
        sol = false;
        break;
      }
    }

    if (sol) {
      cout << "YES" << endl;
    }
  }
}