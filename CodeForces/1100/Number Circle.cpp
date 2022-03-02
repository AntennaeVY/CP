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

  if (a[n - 3] + a[n - 2] <= a[n - 1]) {
    cout << "NO";
  } else {
    swap(a[n - 2], a[n - 1]);

    cout << "YES" << endl;

    for (auto x : a) {
      cout << x << " ";
    }
  }
}