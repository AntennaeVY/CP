#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m), c(m);

  for (auto &it : a) {
    cin >> it;
  }

  for (auto &it : b) {
    cin >> it;
  }

  int i = 0, j = 0;

  while (i < n && j < m) {
    if (a[i] < b[j]) {
      i++;
    } else {
      c[j] = i;
      j++;
    }
  }

  while (j < m) {
    c[j++] = n;
  }

  for (auto x : c) {
    cout << x << " ";
  }
}