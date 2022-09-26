#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long A, B, n;
    cin >> A >> B >> n;

    vector<pair<long long, long long>> d(n);
    for (int i{}; i < n; i++) cin >> d[i].first;
    for (int i{}; i < n; i++) cin >> d[i].second;

    sort(d.begin(), d.end());

    string ans = "YES";

    for (int i{}; i < n; i++) {
      int t1 = (B + d[i].first - 1) / d[i].first;
      int t2 = (d[i].second + A - 1) / A;

      if (t2 > t1) {
        ans = "NO";
        break;
      }

      B -= d[i].first * t2;
    }

    cout << ans << endl;
  }
}