#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &it : a) cin >> it;

    bool ans = true, inc = true;
    int len = 1;

    for (int i = 1; i < n; i++) {
      if (a[i] < a[i - 1] && inc)
        inc = false;
      else if (a[i] > a[i - 1] && !inc)
        ans = false;
    }

    cout << (ans ? "YES" : "NO") << endl;
  }
}