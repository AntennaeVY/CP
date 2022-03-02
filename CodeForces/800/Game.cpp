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

  for (int i{}; i < n - 1; i++) {
    if (i % 2) {
      a.erase(a.begin());
    } else {
      a.pop_back();
    }
  }

  cout << a[0];
}