#include <bits/stdc++.h>

#include <tuple>
using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<unsigned long long> a(n + 3, 0);
  vector<tuple<int, int, int>> op(m + 3);
  vector<int> ps_op(m + 3);
  vector<int> op_times(m + 3, 0);
  vector<int> ps_op_times(m + 3, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= m; i++) {
    int l, r, d;
    cin >> l >> r >> d;

    op[i] = make_tuple(l, r, d);
  }

  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;

    op_times[x]++;
    op_times[y + 1]--;
  }

  vector<long long> sum_cnt(n + 4, 0);

  for (int i = 1; i < m + 2; i++) {
    ps_op_times[i] = ps_op_times[i - 1] + op_times[i];

    sum_cnt[get<0>(op[i])] += 1LL * get<2>(op[i]) * ps_op_times[i];

    sum_cnt[get<1>(op[i]) + 1] -= 1LL * get<2>(op[i]) * ps_op_times[i];
  }

  vector<long long> ps_sum_cnt(n + 4, 0);

  for (int i = 1; i <= n + 1; i++) {
    ps_sum_cnt[i] = ps_sum_cnt[i - 1] + sum_cnt[i];
  }

  for (int i = 1; i <= n; i++) {
    a[i] += ps_sum_cnt[i];
    cout << a[i] << " ";
  }
}