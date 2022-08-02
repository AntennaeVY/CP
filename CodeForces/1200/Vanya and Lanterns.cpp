#include <bits/stdc++.h>
using namespace std;

int main() {
  cout << fixed << setprecision(10);
  int n, l;
  cin >> n >> l;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  sort(a.begin(), a.end());

  int mx_len = 0;

  for (int i = 1; i < n; i++) {
    mx_len = max(mx_len, a[i] - a[i - 1]);
  }

  cout << max(mx_len / 2.0, (double)max(a[0], l - a[n - 1])) << endl;
}