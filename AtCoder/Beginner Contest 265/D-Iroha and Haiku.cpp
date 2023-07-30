#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll N, P, Q, R;
  cin >> N >> P >> Q >> R;

  set<ll> s;
  ll sum = 0;
  s.insert(0);

  for (int i{}; i < N; i++) {
    ll x;
    cin >> x;
    sum += x;

    s.insert(sum);
  }

  for (auto x : s) {
    if (s.find(x + P) != s.end() && s.find(x + P + Q) != s.end() &&
        s.find(x + P + Q + R) != s.end()) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
}