#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  while (n--) {
    unsigned long long q;
    cin >> q;

    if (q == 1) {
      cout << "Neither" << endl;
      continue;
    } else if (q % 2 == 0 && q != 2) {
      cout << "Composite" << endl;
      continue;
    } else {
      if (q == 2) {
        cout << "Prime" << endl;
        continue;
      }

      bool prime = true;

      for (unsigned long long i = 3; i * i <= q; i += 2) {
        if (q % i == 0) {
          prime = false;
          break;
        }
      }

      if (prime) {
        cout << "Prime" << endl;
      } else {
        cout << "Composite" << endl;
      }
    }
  }
}