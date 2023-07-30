#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (auto &x : a) cin >> x;

  sort(a.begin(), a.end());

  int cnt = 0, l = 0, num = 0, freq = -1;
  ll total = 0;

  for (int r{}; r < n; r++) {
    total += a[r];
    cnt++;

    while (1LL * cnt * a[r] - total > k) {
      total -= a[l];
      cnt--;

      l++;
    }

    if (cnt > freq) {
      freq = cnt;
      num = a[r];
    }
  }

  cout << freq << " " << num << endl;
}