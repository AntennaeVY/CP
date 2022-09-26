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

    int cnt = 0;
    bool flag = true;

    for (int i{}; i < n; i++) {
      if (a[i] < 0) cnt++;

      if (a[i] == 0) flag = false;
    }

    if (flag)
      cout << cnt % 2 << endl;
    else
      cout << 0 << endl;
  }
}