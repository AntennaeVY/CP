#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    cout << k / 2 + n - k << endl;

    for (int i = ((k + 1) / 2); i < k; i++) {
      cout << i << " ";
    }

    for (int i = k + 1; i <= n; i++) {
      cout << i << " ";
    }

    cout << endl;
  }
}