#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int c = a, d = b;

    while (b != 0) {
      swap(a, b);

      b %= a;
    }

    int gcd = a;

    cout << gcd << " " << c * d / gcd << endl;
  }
}