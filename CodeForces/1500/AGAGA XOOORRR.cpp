#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &ai : a) cin >> ai;

    vector<int> px(n + 1, 0);

    for (int i = 0; i < n; i++) {
      px[i + 1] = (px[i] ^ a[i]);
    }

    bool can = !px[n];

    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j < n; j++) {
        can |= (px[i] == (px[j] ^ px[i]) && px[i] == (px[n] ^ px[j]));
      }
    }

    cout << (can ? "YES" : "NO") << endl;
  }
}