#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int MAX_N = 2e5 + 10;
vector<int> p(MAX_N), a(MAX_N);

ll calc(ll px, ll n, ll k) {
  vector<bool> vis(n);
  vector<int> q;

  while (!vis[px]) {
    q.push_back(a[px]);
    vis[px] = true;
    px = p[px] - 1;
  }

  ll ans = 0, sum = 0;

  for (int i = 0; i < min(1LL * q.size(), 1ULL * k); i++) {
    ans = max(ans, sum + q[i] * (k - i));
    sum += q[i];
  }

  return ans;
}

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long n, k, pb, ps;
    cin >> n >> k >> pb >> ps;

    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }

    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    ll ansb = calc(pb - 1, n, k);
    ll anss = calc(ps - 1, n, k);

    if (ansb > anss)
      cout << "Bodya" << endl;
    else if (anss > ansb)
      cout << "Sasha" << endl;
    else
      cout << "Draw" << endl;
  }
}