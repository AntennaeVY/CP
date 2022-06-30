#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(n), b(m);

  for (auto &it : a) {
    cin >> it;
  }

  for (auto &it : b) {
    cin >> it;
  }

  int i = 0, j = 0;

  while (i < n && j < m) {
    if (a[i] < b[j])
      cout << a[i++] << " ";
    else
      cout << b[j++] << " ";
  }

  while (i < n) {
    cout << a[i++] << " ";
  }

  while (j < m) {
    cout << b[j++] << " ";
  }
}