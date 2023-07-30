#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> m;

    for (auto &x : a) {
      cin >> x;
      m[x]++;
    }

    int even = 0;

    for (auto x : m) {
      if (x.second % 2 == 0) even++;
    }

    if (even % 2 == 0) {
      cout << m.size() << endl;
    } else {
      cout << m.size() - 1 << endl;
    }
  }
}