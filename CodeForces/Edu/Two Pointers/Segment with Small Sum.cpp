#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  long long s;
  cin >> n >> s;

  vector<int> a(n);

  for (int i{}; i < n; i++) {
    cin >> a[i];
  }

  long long sum = 0, l = 0, mx = 0;

  for (int r{}; r < n; r++) {
    sum += a[r];

    while (sum > s) {
      sum -= a[l];
      l++;
    }

    mx = max(mx, r - l + 1);
  }

  cout << mx << endl;
}