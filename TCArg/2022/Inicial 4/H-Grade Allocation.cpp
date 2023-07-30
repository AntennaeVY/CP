#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m, sum = 0;
    cin >> n >> m;

    for (int i{}; i < n; i++) {
      int x;
      cin >> x;
      sum += x;
    }

    cout << (sum <= m ? sum : m) << endl;
  }
}