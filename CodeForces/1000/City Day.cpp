#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  vector<int> a(n);
  for (auto &i : a) cin >> i;

  for (int i{}; i < n; i++) {
    bool good = true;

    for (int j = i - x; j < i; j++) {
      if (a[max(0, j)] < a[i]) good = false;
    }

    for (int j = i + y; j > i; j--) {
      if (a[min(n - 1, j)] < a[i]) good = false;
    }

    if (good) {
      cout << i + 1 << endl;
      break;
    }
  }
}