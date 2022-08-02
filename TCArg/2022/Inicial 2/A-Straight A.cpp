#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  double k;
  cin >> n >> k;

  vector<int> a(n);

  int sum = 0;
  for (auto &it : a) {
    cin >> it;
    sum += it;
  }

  int l = -1, r = 1e9;
  while (l + 1 < r) {
    int mid = l + (r - l) / 2;

    if ((sum + mid * k) / (double)(n + mid) > (k - 0.5))
      r = mid;
    else
      l = mid;
  }

  if (l > -1)
    cout << l << endl;
  else
    cout << 0 << endl;
}