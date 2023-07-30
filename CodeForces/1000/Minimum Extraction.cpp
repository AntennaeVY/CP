#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (auto &i : a) cin >> i;

    sort(a.begin(), a.end());

    long long mx = a[0];
    long long accum = 0;

    for (int i = 0; i < n; i++) {
      mx = max(mx, a[i] - accum);

      accum += (a[i] - accum);
    }

    cout << mx << endl;
  }
}