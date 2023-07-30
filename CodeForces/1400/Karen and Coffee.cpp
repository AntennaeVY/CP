#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, q;
  cin >> n >> k >> q;

  vector<int> deg(2e5 + 2, 0);
  vector<int> deg_ps(2e5 + 3, 0);
  vector<int> adm_ps(2e5 + 3, 0);

  for (int i{}; i < n; i++) {
    int l, r;
    cin >> l >> r;

    deg[l]++;
    deg[r + 1]--;
  }

  for (int i = 1; i < 2e5 + 2; i++) {
    deg_ps[i] = deg_ps[i - 1] + deg[i];

    adm_ps[i] = adm_ps[i - 1] + (deg_ps[i] >= k);
  }

  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;

    cout << adm_ps[b] - adm_ps[a - 1] << endl;
  }
}