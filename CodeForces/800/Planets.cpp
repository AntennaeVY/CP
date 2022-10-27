#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for (auto &i : a) cin >> i;

    map<int, int> m;

    for (int i{}; i < n; i++) {
      m[a[i]]++;
    }

    long long ans = 0;

    for (auto x : m) {
      ans += min(x.second, c);
    }

    cout << ans << endl;
  }
}