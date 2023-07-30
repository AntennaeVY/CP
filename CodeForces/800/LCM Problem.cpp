#include <iostream>
using namespace std;

int main() {
  int n, l, r;
  cin >> n;

  while (n--) {
    cin >> l >> r;

    if (2 * l > r) {
      cout << -1 << " " << -1 << endl;
    } else {
      cout << l << " " << 2 * l << endl;
    }
  }
}