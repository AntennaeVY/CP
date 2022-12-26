#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    vector<pair<int, int>> v;

    for (int i = 0; i < 3; i++) {
      int xi, yi;
      cin >> xi >> yi;

      v.push_back({xi, yi});
    }

    bool ans = true;

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (j == i) continue;

        for (int k = 0; k < 3; k++) {
          if (k == j || k == i) continue;

          if (v[k].first == v[i].first && v[k].second == v[j].second)
            ans = false;
        }
      }
    }

    cout << (ans ? "YES" : "NO") << endl;
  }
}