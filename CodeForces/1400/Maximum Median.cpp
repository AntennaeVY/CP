#include <bits/stdc++.h>
using namespace std;

bool good(vector<int> &a, int k, int mid) {
  int accum = 0;

  for (int i = a.size() / 2; i < a.size(); i++) {
    accum += max(0, mid - a[i]);

    if (accum > k) return false;
  }

  return true;
}

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (auto &it : a) cin >> it;

  sort(a.begin(), a.end());

  int l = 0, r = 1e10;

  while (l + 1 < r) {
    int mid = l + (r - l) / 2;

    if (good(a, k, mid))
      l = mid;
    else
      r = mid;
  }

  cout << l << endl;
}