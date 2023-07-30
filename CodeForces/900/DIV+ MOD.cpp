#include <math.h>

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int l, r, a;

    cin >> l >> r >> a;

    int mx = (r - (r % a)) - 1;

    if (mx < l) {
      mx = r;
    }

    cout << max(mx / a + mx % a, r / a + r % a) << endl;
  }
}