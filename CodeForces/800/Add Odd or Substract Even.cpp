#include <math.h>

#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int a, b;
    cin >> a >> b;

    int diff = b - a;

    if (diff == 0) {
      cout << 0 << endl;
    } else if (diff % 2 && diff > 0 || !(diff % 2) && diff < 0) {
      cout << 1 << endl;
    } else {
      cout << 2 << endl;
    }
  }
}