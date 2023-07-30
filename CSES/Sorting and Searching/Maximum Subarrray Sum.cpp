#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<long long> a(n);
  for (auto &it : a) cin >> it;

  long long s = 0, b = a[0];

  for (int i{}; i < n; i++) {
    s = max(s + a[i], a[i]);
    b = max(b, s);
  }

  cout << b << endl;
}