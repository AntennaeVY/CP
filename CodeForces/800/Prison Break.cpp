
#include <math.h>

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    // Manhattan Distance
    cout << max(r - 1, n - r) + max(c - 1, m - c) << endl;
  }
}