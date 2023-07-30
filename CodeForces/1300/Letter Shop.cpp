#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> s_ps;

bool good(int mid, vector<int> &t_state) {
  for (int i{}; i < 26; i++) {
    if (s_ps[mid][i] < t_state[i]) return false;
  }

  return true;
}

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  vector<int> state(26, 0);

  for (int i = 0; i < n; i++) {
    state[(int)s[i] - 97]++;
    s_ps.push_back(state);
  }

  int m;
  cin >> m;

  vector<string> t(m);
  for (auto &x : t) cin >> x;

  vector<vector<int>> t_state(m, vector<int>(26, 0));

  for (int i{}; i < m; i++) {
    for (int j{}; j < t[i].size(); j++) {
      t_state[i][(int)t[i][j] - 97]++;
    }

    int l = -1, r = n;
    while (l + 1 < r) {
      int mid = l + (r - l) / 2;

      if (good(mid, t_state[i]))
        r = mid;
      else
        l = mid;
    }

    int ans = 0;
    for (auto x : s_ps[r]) {
      ans += x;
    }

    cout << ans << endl;
  }
}