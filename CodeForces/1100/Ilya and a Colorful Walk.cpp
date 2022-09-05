#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> c(n);
  for (auto &it : c) cin >> it;

  int i = n - 1, j = 0;

  for (; i > 0; i--) {
    if (c[i] != c[0]) break;
  }

  for (; j < n - 1; j++) {
    if (c[j] != c[n - 1]) break;
  }

  cout << max(i, n - 1 - j) << endl;
}