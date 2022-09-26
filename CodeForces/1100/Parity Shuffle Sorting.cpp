#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &it : a) cin >> it;

    bool sorted = true;

    for (int i = 1; i < n; i++) {
      if (a[i] < a[i - 1]) sorted = false;
    }

    if (n == 1 || sorted) {
      cout << 0 << endl;
      continue;
    }

    cout << n - 1 << endl;

    cout << 1 << " " << n << endl;

    for (int i = 1; i < n - 1; i++) {
      if ((a[i] + a[0]) % 2 == 1)
        cout << 1 << " " << i + 1 << endl;
      else
        cout << i + 1 << " " << n << endl;
    }
  }
}