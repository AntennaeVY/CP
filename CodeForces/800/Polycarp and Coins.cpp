#include <math.h>

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    double n;
    cin >> n;

    int c2{round(n / 3)};
    int c1{n - c2 * 2};
    int count{c1 + 2 * c2};

    while (count != n) {
      if (count + 1 <= n) {
        c1++;
        count++;
      }

      if (count + 2 <= n) {
        c2++;
        count += 2;
      }
    }
    cout << c1 << " " << c2 << endl;
  }
}
