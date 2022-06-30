#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int l = 0, r = a.size() - 1;

    while (l <= r) {
      if (l == r)
        cout << a[l];
      else
        cout << a[l] << " " << a[r] << " ";

      r--;
      l++;
    }

    cout << endl;
  }
}