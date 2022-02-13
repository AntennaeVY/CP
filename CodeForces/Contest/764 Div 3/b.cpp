#include <math.h>

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;

    if ((a == 2 && b == 1 && c == 1) || (a == 1 && b == 1 && c == 2)) {
      cout << "NO" << endl;
      continue;
    }

    if (a - b == b - c) {
      cout << "YES" << endl;
      continue;
    }

    if (a == b && b % c == 0) {
      cout << "YES" << endl;
      continue;
    }

    if (b == c && b % a == 0) {
      cout << "YES" << endl;
      continue;
    }

    if (a == c && c % b == 0) {
      cout << "YES" << endl;
      continue;
    }

    if (abs(a - c) % b == 0) {
      cout << "YES" << endl;
      continue;
    }

    // 4 15 18
    // c - b > 0 -> b - (c - b) % a == 0 ?

    if (c - b > 0 && (b - (c - b)) % a == 0) {
      cout << "YES" << endl;
      continue;
    }

    // 3 18 15
    // c - b < 0 ->  ((b - c) + b)%a == 0 ?

    if (c - b < 0 && ((b - c) + b) % a == 0) {
      cout << "YES" << endl;
      continue;
    }

    // 6 10 7
    // b - a > 0 -> ((b - a) + b) % c == 0?

    if (b - a > 0 && ((b - a) + b) % c == 0) {
      cout << "YES" << endl;
      continue;
    }

    // 10 8 3
    // b - a < 0 -> (b - (b - a)) % c == 0?

    if (b - a < 0 && (b - (b - a)) % c == 0) {
      cout << "YES" << endl;
      continue;
    }

    cout << "NO" << endl;
  }
}