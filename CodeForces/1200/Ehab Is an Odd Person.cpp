#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);

  for (auto &it : a) cin >> it;

  bool ok = true;

  for (int i = 0; i < n - 1; i++) {
    ok &= a[i] % 2 == a[i + 1] % 2;
  }

  if (!ok) {
    sort(a.begin(), a.end());
  }

  for (auto x : a) {
    cout << x << " ";
  }
}