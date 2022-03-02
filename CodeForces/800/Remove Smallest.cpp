#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i{}; i < n; i++) {
      cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (size_t i{}; i < a.size() - 1; i++) {
      if (abs(a[i] - a[i + 1]) <= 1) {
        int smlrindx = (min(a[i], a[i + 1]) == a[i] ? i : i + 1);
        a.erase(a.begin() + smlrindx);
        i = -1;
      }
    }

    cout << (a.size() == 1 ? "YES" : "NO") << endl;
  }
}