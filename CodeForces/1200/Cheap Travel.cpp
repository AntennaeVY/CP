#include <math.h>

#include <iostream>
using namespace std;

int main() {
  int n, m, a, b;
  cin >> n >> m >> a >> b;

  if (m * a <= b) {
    cout << n * a;
  } else {
    cout << (n / m) * b + min((n % m) * a, b);
  }
}