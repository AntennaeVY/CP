#include <bits/stdc++.h>
using namespace std;

int ans = 0, n, S;

bool good(vector<int> &a, int k) {
  vector<long long> b(n);

  for (long long i{}; i < n; i++) {
    b[i] = a[i] + (i + 1) * k;
  }

  sort(b.begin(), b.end());

  int l = 0;
  long long sum = 0;

  for (int r{}; r < n; r++) {
    sum += b[r];

    while (r - l + 1 > k) {
      sum -= b[l];
      l++;
    }

    if (sum <= S && (r - l + 1) == k) {
      ans = sum;
      return true;
    }
  }

  return false;
}

int main() {
  cin >> n >> S;

  vector<int> a(n);

  for (int i{}; i < n; i++) {
    cin >> a[i];
  }

  int l = -1, r = n + 1;

  while (l + 1 < r) {
    int mid = l + (r - l) / 2;

    if (good(a, mid))
      l = mid;
    else
      r = mid;
  }

  cout << l << " " << ans << endl;
}