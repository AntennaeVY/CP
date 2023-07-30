#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n;

  vector<long long> stones(n, 0), ps_stones(n + 1, 0), ps_cheap(n + 1, 0);

  for (int i{}; i < n; i++) {
    cin >> stones[i];
    ps_stones[i + 1] = ps_stones[i] + stones[i];
  }

  sort(stones.begin(), stones.end());

  for (int i{}; i < n; i++) {
    ps_cheap[i + 1] = ps_cheap[i] + stones[i];
  }

  cin >> m;

  for (int i{}; i < m; i++) {
    int type, l, r;
    cin >> type >> l >> r;

    if (type == 1) {
      cout << ps_stones[r] - ps_stones[l - 1] << endl;
    } else {
      cout << ps_cheap[r] - ps_cheap[l - 1] << endl;
    }
  }
}