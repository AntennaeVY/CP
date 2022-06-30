#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> t(n);

  for (auto &it : t) cin >> it;

  int l = 0, r = n - 1;
  int a = t[l], b = t[r];
  int alice = 0, bob = 0;

  if (n == 1) {
    cout << 1 << " " << 0 << endl;
    return 0;
  }

  while (r - l >= 0) {
    if (a > b) {
      a -= b;
      b = t[--r];
      bob++;
    } else if (a < b) {
      b -= a;
      a = t[++l];
      alice++;
    } else {
      a = t[++l];
      b = t[--r];

      if (r != l) {
        bob++;
      }

      alice++;
    }
  }

  cout << alice << " " << bob << endl;
}