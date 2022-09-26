#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 1; i <= n; i++) a[i - 1] = i;

    cout << n << endl;

    for (int j : a) {
      cout << j << " ";
    }

    cout << endl;

    for (int i = 1; i < n; i++) {
      swap(a[i], a[i - 1]);

      for (int j : a) {
        cout << j << " ";
      }

      cout << endl;
    }
  }
}