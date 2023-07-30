#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> Q(1000);
  for (int i = 999; i >= 0; i--) {
    Q[i] = 1000 - i;
  }

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> p(n), q(Q), r(n);
    for (auto &i : p) cin >> i;

    if (n == 1) {
      cout << -1 << endl;
      continue;
    }

    for (int i{}; i < n; i++) {
      int curr = q.back();
      q.pop_back();

      if (p[i] == curr && i != n - 1) {
        r[i] = q.back();
        q.pop_back();
        q.push_back(curr);
      } else
        r[i] = curr;

      if (p[i] == curr && i == n - 1) swap(r[i], r[i - 1]);
    }

    for (auto i : r) cout << i << " ";
    cout << endl;
  }
}