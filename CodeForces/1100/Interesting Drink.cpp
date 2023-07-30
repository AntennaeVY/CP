#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> x(n);
  for (auto &it : x) cin >> it;

  int q;
  cin >> q;

  vector<int> m(q);
  for (auto &it : m) cin >> it;

  sort(x.begin(), x.end());

  for (auto y : m) {
    int l = -1, r = n;

    while (r - l > 1) {
      int mid = l + (r - l) / 2;

      if (x[mid] > y)
        r = mid;
      else
        l = mid;
    }

    cout << l + 1 << endl;
  }
}