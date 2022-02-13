#include <math.h>

#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;

  int div = 3, prevDiv = 1;

  if (n % 2 == 0) {
    prevDiv = 2;
    while (n % 2 == 0) n /= 2;
  }

  int maxDiv = sqrt(n);

  while (n > 1 && div <= sqrt(n)) {
    if (n % div == 0) {
      prevDiv = div;

      while (n % div == 0) n /= div;
      maxDiv = sqrt(n);
    }

    div += 2;
  }

  if (n == 1) {
    cout << prevDiv;
  } else {
    cout << n;
  }
}