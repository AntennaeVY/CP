#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);

  for (auto &it : a) cin >> it;

  sort(a.begin(), a.end());

  if (k > 0) {
    if (a[k - 1] == a[k]) {
      cout << -1;
    } else {
      cout << a[k - 1];
    }
  } else {
    if (a[0] > 1) {
      cout << a[0] - 1;
    } else {
      cout << -1;
    }
  }
}