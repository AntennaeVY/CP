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

    int z = count(a.begin(), a.end(), 0);
    int o = count(a.begin(), a.end(), 1);

    if (!o) {
      cout << 0 << endl;
      continue;
    }

    cout << (1LL << z) * o << endl;
  }
}