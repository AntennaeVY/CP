#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (auto &it : a) cin >> it;

  sort(a.begin(), a.end());

  int cnt = 0;

  for (int i = 1; i < n; i += 2) {
    cnt += a[i] - a[i - 1];
  }

  cout << cnt;
}