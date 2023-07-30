#include <bits/stdc++.h>

#include <map>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    map<int, int> a;

    for (int i{}; i < n; i++) {
      int x;
      cin >> x;

      a[x]++;
    }

    bool found = false;

    for (auto it : a) {
      if (it.second >= 3) {
        found = true;
        cout << it.first << endl;
        break;
      }
    }

    if (!found) {
      cout << -1 << endl;
    }
  }
}