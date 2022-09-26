#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    if (n == 1 && k == 1) {
      cout << "R" << endl;
      continue;
    } else if (k > ((n + 1) / 2)) {
      cout << -1 << endl;
      continue;
    }

    for (int i{}; i < n; i++) {
      for (int j{}; j < n; j++) {
        if (i == j && !(i % 2) && k > 0) {
          cout << "R";
          k--;
        } else
          cout << ".";
      }
      cout << endl;
    }
  }
}