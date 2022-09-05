#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> r;
  for (int i{}; i < n; i++) {
    int a, b;
    cin >> a >> b;

    r.push_back(make_pair(a, b));
  }

  int mn = 5000;
  string ans = "maybe";

  for (int i{}; i < n; i++) {
    if (r[i].first != r[i].second) {
      cout << "rated" << endl;
      return 0;
    }

    if (min(mn, r[i].first) != r[i].first) {
      ans = "unrated";
    }

    mn = min(mn, r[i].first);
  }

  cout << ans << endl;
}