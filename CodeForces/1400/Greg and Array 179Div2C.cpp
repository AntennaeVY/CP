#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<int> a(n);
  for (auto &x : a) cin >> x;

  vector<tuple<int, int, int>> o(m + 1);
  for (int i{}; i < m; i++) {
    int l, r, d;
    cin >> l >> r >> d;

    o[i] = make_tuple(l, r, d);
  }

  vector<pair<int, int>> q(k);
  for (int i{}; i < k; i++) {
    int x, y;
    cin >> x >> y;

    q[i] = make_pair(x, y);
  }

  vector<int> pre_ps_o(m + 2, 0);
  for (int i{}; i < k; i++) {
    pre_ps_o[q[i].first]++;
    pre_ps_o[q[i].second + 1]--;
  }

  vector<long long> ps_o(m + 2, 0);
  for (int i = 1; i < m + 2; i++) {
    ps_o[i] = ps_o[i - 1] + pre_ps_o[i];
  }

  vector<long long> pre_ps_a(n + 2);
  for (int i{}; i < m + 1; i++) {
    pre_ps_a[get<0>(o[i])] += get<2>(o[i]) * ps_o[i + 1];
    pre_ps_a[get<1>(o[i]) + 1] -= get<2>(o[i]) * ps_o[i + 1];
  }

  vector<long long> ps_a(n + 2, 0);
  for (int i = 1; i < n + 2; i++) {
    ps_a[i] = ps_a[i - 1] + pre_ps_a[i];
  }

  vector<long long> ans(n);
  for (int i = 1; i < n + 1; i++) {
    ans[i - 1] = a[i - 1] + ps_a[i];
  }

  for (auto x : ans) {
    cout << x << " ";
  }
}