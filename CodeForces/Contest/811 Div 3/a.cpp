#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, H, M;
    cin >> n >> H >> M;

    vector<int> a(n);

    for (int i{}; i < n; i++) {
      int h, m;
      cin >> h >> m;

      h *= 60;

      a[i] = h + m;
    }

    sort(a.begin(), a.end());

    // for (auto x : a) {
    // cout << x << endl;
    // }

    int time = H * 60 + M;
    int ansh, ansm, anst;

    bool found = false;

    for (int i{}; i < n; i++) {
      if (a[i] >= time) {
        found = true;
        anst = a[i] - time;
        break;
      }
    }

    if (!found) {
      anst = a[0] + (24 * 60 - time);
    }

    ansh = anst / 60;
    ansm = anst % 60;

    cout << ansh << " " << ansm << endl;
  }
}