#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll n, I;
  cin >> n >> I;

  vector<int> a(n), s, ps;
  map<int, int> m;

  for (auto &x : a) {
    cin >> x;

    m[x]++;
  }

  sort(a.begin(), a.end());

  for (auto x : m) {
    s.push_back(x.first);
  }

  ps.resize(m.size() + 1);
  ps[0] = 0;

  for (int i = 0; i < m.size(); i++) {
    ps[i + 1] = ps[i] + m[s[i]];
  }

  int mx = 0, l = 0;

  for (int r{}; r < m.size(); r++) {
    while (ceil(log2(r - l + 1)) * n > 8 * I) {
      l++;
    }

    mx = max(mx, ps[r + 1] - ps[l]);
  }

  cout << n - mx << endl;
}