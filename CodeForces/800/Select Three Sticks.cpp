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

    sort(a.begin(), a.end());

    int mn = INT_MAX;

    for (int i = 1; i < n - 1; i++) {
      mn = min(mn, a[i + 1] - a[i - 1]);
    }

    cout << mn << endl;
  }
}