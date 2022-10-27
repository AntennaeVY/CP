#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), accum(k, 0);
    for (auto &it : a) cin >> it;

    for (int i{}; i < n; i++) {
      accum[(i + 1) % k] = max(accum[(i + 1) % k], a[i]);
    }

    long long sum = 0;
    for (auto x : accum) sum += x;

    cout << sum << endl;
  }
}