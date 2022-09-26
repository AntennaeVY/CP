#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> l(n), r(n);
    for (int i{}; i < n; i++) {
      cin >> l[i] >> r[i];
    }

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    cout << max(l.back() - r.front(), 0) << endl;
  }
}